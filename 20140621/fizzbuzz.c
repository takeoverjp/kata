#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

static void
print_usage (void)
{
  printf ("[USAGE] ./a.out min max\n");
}

int
main (int argc, char *argv[])
{
  int i;
  int min,max;

  if (argc != 3)
    goto ERROR;
  
  errno = ELAST;
  min = strtol(argv[1], NULL, 10);
  if (min == 0 && (errno == EINVAL || errno == ERANGE))
    goto ERROR;

  errno = ELAST;
  max = strtol(argv[2], NULL, 10);
  if (min == 0 && (errno == EINVAL || errno == ERANGE))
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
  print_usage ();
  exit (EXIT_FAILURE);
}
