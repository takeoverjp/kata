#include <stdio.h>

static const char*
to_str (int num, char *buf, int size)
{
  if (num % 15 == 0)
    sprintf (buf, "FizzBuzz");
  else if (num % 3 == 0)
    sprintf (buf, "Fizz");
  else if (num % 5 == 0)
    sprintf (buf, "Buzz");
  else
    sprintf (buf, "%d", num);
}

static void
fizzbuzz (int min, int max)
{
  int i = 0;
  for (i = min; i <= max; i++)
    {
      char buf[128] = {0};
      to_str (i, buf, sizeof(buf));
      printf ("%s\n", buf);
    }
}

int
main (void)
{
  fizzbuzz (1, 100);
}
