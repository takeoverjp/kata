#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>

static const long long TOTAL_BYTES = 1 * 1024UL * 1024 * 1024;
#define CACHE_LINE_SIZE 64

static long
diff_nsec (struct timespec *before, struct timespec *after)
{
  return (after->tv_sec - before->tv_sec) * 1000000000
    + (after->tv_nsec - before->tv_nsec);
}

int
main (int argc, char *argv[])
{
  if (argc <= 1)
    {
      fprintf (stderr, "[USAGE] %s WORKSET_KB\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  long size = strtol (argv[1], NULL, 10) * 1024;

  char *buf = mmap (NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (buf == MAP_FAILED)
    {
      perror ("mmap");
      exit (EXIT_FAILURE);
    }

  struct timespec before, after;
  clock_gettime (CLOCK_MONOTONIC, &before);

  for (long i = 0; i < TOTAL_BYTES / (size / CACHE_LINE_SIZE); i++)
    for (long j = 0; j < size; j += CACHE_LINE_SIZE)
      buf[j] = 0;

  clock_gettime (CLOCK_MONOTONIC, &after);

  int ret = munmap (buf, size);
  if (ret < 0)
    {
      perror ("munmap");
      exit (EXIT_FAILURE);
    }

  printf ("%f\n", (double)diff_nsec(&before, &after) / 1000000000.0f);
  
  return 0;
}
