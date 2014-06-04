#include <stdio.h>
#include <stdlib.h>

static int
fizzbuzz (int min, int max)
{
  int i;

  if (min >= max)
    return -1;

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

  return 0;
}

int
main (int argc, char *argv[])
{
  int ret = -1;
  int min = 1;
  int max = 100;

  if (argc != 3)
    {
      fprintf (stderr, "invalid argument\n");
      fprintf (stderr, "[usage] ./a.out min max\n");
      exit (EXIT_FAILURE);
    }

  min = strtol (argv[1], NULL, 10);
  max = strtol (argv[2], NULL, 10);

  ret = fizzbuzz (min, max);
  if (ret < 0)
    {
      fprintf (stderr, "invalid argument (min = %d, max = %d)\n", min, max);
      exit (EXIT_FAILURE);
    }

  exit (EXIT_SUCCESS);
}
