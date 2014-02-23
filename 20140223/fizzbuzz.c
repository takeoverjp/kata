#include <stdio.h>

static void
to_str (int i)
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

static void
fizzbuzz (int min, int max)
{
  int i;
  for (i = min; i <= max; i++)
    {
      to_str (i);
    }
}

int
main (void)
{
  fizzbuzz (1, 100);
  return 0;
}
