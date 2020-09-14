#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <zlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <zlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>

#define LOGPRINTF(...) do {                     \
    fprintf (kmsg, "[core_pipe] " __VA_ARGS__); \
    fflush (kmsg);                              \
} while(0)

static u_char is_verbose = 0;
static FILE* kmsg = NULL;

static inline long
diff_ms (const struct timespec* const start,
         const struct timespec* const end)
{
  return (end->tv_sec - start->tv_sec) * 1000
    + (end->tv_nsec % 1000000 - end->tv_nsec % 1000000);
}

static inline long
tv2ms (const struct timeval* const tv)
{
  return tv->tv_sec * 1000 + tv->tv_usec / 1000;
}

static int
is_core (const struct dirent * const dent)
{
  return strncmp (dent->d_name, "core_", 5) == 0;
}

static int
remove_old_cores (const int max_num)
{
  struct dirent **namelist;
  int core_num = scandir ("out", &namelist, is_core, alphasort);

  if (is_verbose)
    LOGPRINTF ("core_num = %d\n", core_num);

  if (core_num <= 0)
    return 0;

  int last_core_index = 0;
  sscanf (namelist[core_num-1]->d_name, "core_%03d_", &last_core_index);

  if (is_verbose)
    LOGPRINTF ("last_core = %s(%d)\n",
               namelist[core_num-1]->d_name, last_core_index);

  if (max_num < 0 || core_num < max_num)
    return last_core_index + 1;

  for (int i = 0; i <= core_num - max_num; i++)
    {
      char path[PATH_MAX];
      snprintf (path, sizeof(path), "out/%s", namelist[i]->d_name);
      remove (path);

      LOGPRINTF ("remove %s\n", path);
    }

  return last_core_index + 1;
}

static void
disable_coredump (void)
{
  const struct rlimit disable = {0, 0};
  int ret = setrlimit (RLIMIT_CORE, &disable);
  if (ret < 0)
    perror ("setrlimit");
}

#define CHUNK 16384
static int
def (FILE *source, FILE*const dest, int level)
{
  int ret, flush;
  unsigned have;
  z_stream strm;
  unsigned char in[CHUNK];
  unsigned char out[CHUNK];

  /* allocate deflate state */
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  ret = deflateInit2 (&strm, level,
                      Z_DEFLATED, 31, 8, Z_DEFAULT_STRATEGY);
  if (ret != Z_OK)
    return ret;

  /* compress until end of file */
  do
    {
      strm.avail_in = fread (in, 1, CHUNK, source);
      if (ferror (source))
        {
          (void)deflateEnd (&strm);
          return Z_ERRNO;
        }
      flush = feof (source) ? Z_FINISH : Z_NO_FLUSH;
      strm.next_in = in;

      /* run deflate() on input until output buffer not full, finish
         compression if all of source has been read in */
      do
        {
          strm.avail_out = CHUNK;
          strm.next_out = out;
          ret = deflate (&strm, flush);    /* no bad return value */
          assert (ret != Z_STREAM_ERROR);  /* state not clobbered */
          have = CHUNK - strm.avail_out;
          if (fwrite (out, 1, have, dest) != have || ferror (dest))
            {
              (void)deflateEnd (&strm);
              return Z_ERRNO;
            }
        }
      while (strm.avail_out == 0);
      assert (strm.avail_in == 0);     /* all input will be used */

      /* done when last data in file processed */
    }
  while (flush != Z_FINISH);
  assert (ret == Z_STREAM_END);        /* stream will be complete */

  /* clean up and return */
  (void)deflateEnd (&strm);
  return Z_OK;
}

static void
libz_error (const int ret, FILE* source, FILE* dest)
{
  switch (ret)
    {
    case Z_ERRNO:
      if (ferror (source))
        LOGPRINTF ("error reading stdin\n");
      if (ferror (dest))
        LOGPRINTF ("error writing stdout\n");
      break;
    case Z_STREAM_ERROR:
      LOGPRINTF ("invalid compression level\n");
      break;
    case Z_DATA_ERROR:
      LOGPRINTF ("invalid or incomplete deflate data\n");
      break;
    case Z_MEM_ERROR:
      LOGPRINTF ("out of memory\n");
      break;
    case Z_VERSION_ERROR:
      LOGPRINTF ("zlib version mismatch!\n");
    }
}

static void
show_usage_and_exit (void)
{
  fputs ("[USAGE] core_pipe OUTPUT_DIR SEC EXEC_NAME\n"
         "    -v: Enable verbose log\n"
         "    -n NUM: Set maximum core file number\n"
         "    -s SIZE: Set maximum compressed core size [MB]\n",
         stderr);
  exit (EXIT_FAILURE);
}

int
main (int argc, char *argv[])
{
  disable_coredump ();

  int opt;
  int max_num = -1;
  int max_size_mb = -1;

  kmsg = fopen ("/dev/kmsg", "w+");
  if (!kmsg)
    kmsg = stdout;

  while ((opt = getopt (argc, argv, "vn:s:")) != -1)
    {
      switch (opt) {
      case 'v':
        is_verbose = 1;
        break;
      case 'n':
        max_num = strtol (optarg, NULL, 10);
        break;
      case 's':
        max_size_mb = strtol (optarg, NULL, 10);
        (void) max_size_mb;
        break;
      default:
        show_usage_and_exit ();
      }
    }

  if (argc != optind + 3)
    show_usage_and_exit ();

  const char* const output_dir = argv[optind];
  const time_t sec = strtoll (argv[optind+1], NULL, 10);
  const char* const executable = argv[optind+2];

  struct tm time;
  memset (&time, 0x0, sizeof(time));
  gmtime_r (&sec, &time);

  const int core_index = remove_old_cores (max_num);

  char core_name[PATH_MAX];
  snprintf (core_name, sizeof(core_name),
            "%s/core_%03d_%04d%02d%02d_%02d%02d%02d_%s.gz",
            output_dir,
            core_index,
            time.tm_year + 1900,
            time.tm_mon + 1,
            time.tm_mday,
            time.tm_hour,
            time.tm_min,
            time.tm_sec,
            executable);
  FILE* const dest = fopen (core_name, "wb");
  if (!dest)
    {
      fputs (core_name, stderr);
      perror ("fopen");
      exit (EXIT_FAILURE);
    }

  LOGPRINTF ("start to store %s\n", core_name);
  int ret = def (stdin, dest, Z_DEFAULT_COMPRESSION);
  if (ret != Z_OK)
    libz_error (ret, stdin, stdout);
  LOGPRINTF("finish to store %s\n", core_name);

  fclose (dest);

  exit (EXIT_SUCCESS);
}
