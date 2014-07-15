#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

static void
fizzbuzz (int min, int max)
{
  int i;
  for (i = min; i <= max; i++)
    {
      if (i % 15 == 0)
        printf ("FizzBuzz\n");
      else if (i % 3 == 0)
        printf ("Fizz\n");
      else if (i % 5 == 0)
        printf ("Buzz\n");
      else
        printf ("%d\n", i);
    }
}

int
main (int argc, char *argv[])
{
  int min, max;

  if (argc != 3)
    goto ERROR;

  errno = 0;
  min = strtol (argv[1], NULL, 10);
  if (errno != 0)
    goto ERROR;
    
  errno = 0;
  max = strtol (argv[2], NULL, 10);
  if (errno != 0)
    goto ERROR;

  if (min > max)
    goto ERROR;

  fizzbuzz (min, max);
  exit (EXIT_SUCCESS);

 ERROR:
  fprintf (stderr, "[USAGE] ./a.out min max\n");
  exit (EXIT_FAILURE);
}
