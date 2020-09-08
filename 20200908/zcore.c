#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <zlib.h>

#define CHUNK 16384

/* Compress from file source to file dest until EOF on source.
   def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_STREAM_ERROR if an invalid compression
   level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
   version of the library linked do not match, or Z_ERRNO if there is
   an error reading or writing the files. */
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
zerr (const int ret, FILE* source, FILE* dest)
{
  fputs ("zpipe: ", stderr);
  switch (ret)
    {
    case Z_ERRNO:
      if (ferror (source))
        fputs ("error reading stdin\n", stderr);
      if (ferror (dest))
        fputs ("error writing stdout\n", stderr);
      break;
    case Z_STREAM_ERROR:
      fputs ("invalid compression level\n", stderr);
      break;
    case Z_DATA_ERROR:
      fputs ("invalid or incomplete deflate data\n", stderr);
      break;
    case Z_MEM_ERROR:
      fputs ("out of memory\n", stderr);
      break;
    case Z_VERSION_ERROR:
      fputs ("zlib version mismatch!\n", stderr);
    }
}

static void
show_usage_and_exit (void)
{
  fputs ("[USAGE] zcore OUTPUT_DIR SEC EXECUTABLE SIGNAL PID TID SEC\n", stderr);
  exit (EXIT_FAILURE);
}

int
main (int argc, char *argv[])
{
  if (argc != 7)
    show_usage_and_exit ();

  int idx = 1;
  const char* const output_dir = argv[idx++];
  const long long sec = strtoll (argv[idx++], NULL, 10);
  const char* const executable = argv[idx++];
  const int signo = strtol (argv[idx++], NULL, 10);
  const long pid = strtol (argv[idx++], NULL, 10);
  const long tid = strtol (argv[idx++], NULL, 10);

  char core_name[PATH_MAX];
  snprintf (core_name, sizeof(core_name), "%s/core_%010lld_%s_%02d_%05ld_%05ld.gz",
            output_dir, sec, executable, signo, pid, tid);
  FILE* const dest = fopen (core_name, "wb");
  if (!dest)
    {
      fputs (core_name, stderr);
      perror ("fopen");
      exit (EXIT_FAILURE);
    }

  int ret = def (stdin, dest, Z_DEFAULT_COMPRESSION);
  if (ret != Z_OK)
    zerr (ret, stdin, stdout);

  fclose (dest);

  exit (EXIT_SUCCESS);
}
