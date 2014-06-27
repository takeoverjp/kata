#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int
main (int argc, char *argv[])
{
  int i,max,min;

  if (argc != 3)
    goto ERROR;

  errno = 0;
  min = strtol (argv[1], NULL, 10);
  if (min == 0 && (errno == EINVAL || errno == ERANGE))
    goto ERROR;
  
  errno = 0;
  max = strtol (argv[2], NULL, 10);
  if (max == 0 && (errno == EINVAL || errno == ERANGE))
    goto ERROR;

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

 ERROR:
  printf ("[USAGE] ./a.out min max\n");
  exit (EXIT_FAILURE);
}
