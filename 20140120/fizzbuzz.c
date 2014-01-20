#include <stdio.h>
#include <sys/types.h>

static u_char
is_dividable (int dividee, int divider)
{
  return ((dividee % divider) == 0);
}

static u_char
is_fizz (int num)
{
  return is_dividable (num, 3);
}

static u_char
is_buzz (int num)
{
  return is_dividable (num, 5);
}

static void
fizzbuzz (int num)
{
  if (is_fizz (num) && is_buzz (num))
    printf ("FizzBuzz\n");
  else if (is_fizz (num))
    printf ("Fizz\n");
  else if (is_buzz (num))
    printf ("Buzz\n");
  else
    printf ("%d\n", num);
}

int
main (void)
{
  int i = 1;
  for (i = 1; i <= 100; i++)
    fizzbuzz (i);
  return 0;
}
