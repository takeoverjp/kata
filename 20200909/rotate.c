#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <dirent.h>

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
  fprintf (kmsg, "core_num = %d\n", core_num);
  fflush (kmsg);

  if (core_num <= 0)
    return 0;

  if (core_num < max_num)
    return 0;

  for (int i = 0; i <= core_num - max_num; i++)
    {
      char path[PATH_MAX];
      snprintf (path, sizeof(path), "out/%s", namelist[i]->d_name);
      remove (path);
      fprintf (kmsg, "remove %s\n", path);
      fflush (kmsg);
    }

  return 0;
}

int
main (int argc, char* argv[])
{
  int opt;
  int max_num = 10;

  kmsg = fopen ("/dev/kmsg", "w+");
  if (!kmsg)
    kmsg = stdout;

  while ((opt = getopt (argc, argv, "m:")) != -1)
    {
      switch (opt) {
      case 'g':
        max_num = strtol (optarg, NULL, 10);
        break;
      default:
        fprintf (stderr, "Usage: %s [-m max_num] [-v] name\n",
                 argv[0]);
        exit (EXIT_FAILURE);
      }
    }

  fprintf (kmsg, "max_num = %d\n", max_num);
  fflush (kmsg);

  struct timespec start, end;
  int ret = clock_gettime (CLOCK_MONOTONIC, &start);
  if (ret < 0)
    {
      fprintf (kmsg, "clock_gettime start error %d\n", errno);
      fflush (kmsg);
    }

  remove_old_cores (max_num);

  ret = clock_gettime (CLOCK_MONOTONIC, &end);
  if (ret < 0)
    {
      fprintf (kmsg, "clock_gettime end error %d\n", errno);
      fflush (kmsg);
    }

  long real_ms = diff_ms (&start, &end);
  struct rusage usage;
  ret = getrusage (RUSAGE_SELF, &usage);
  if (ret < 0)
    {
      fprintf (kmsg, "getrusage error %d\n", errno);
      fflush (kmsg);
    }

  fprintf (kmsg, "real: %ldms\n", real_ms);
  fflush (kmsg);
  fprintf (kmsg, "user: %ldms, sys: %ldms\n",
           tv2ms (&usage.ru_utime),
           tv2ms (&usage.ru_stime));
  fflush (kmsg);

  exit (EXIT_SUCCESS);
}
