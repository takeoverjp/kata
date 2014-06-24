#include <stdio.h>

int
main (void)
{
  int i;
  for (i = 1; i <= 100; i++)
    {
      if (i % 15 == 0)
        printf ("FizzBuzz\n");
      if (i % 3 == 0)
        printf ("Fizz\n");
      if (i % 5 == 0)
        printf ("Buzz\n");
      else
        printf ("%d\n", i);
    }
  return 0;
}
