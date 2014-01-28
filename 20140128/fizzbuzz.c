#include <stdio.h>
#include <sys/types.h>

static u_char
is_fizz (int num)
{
  return num % 3 == 0;
}

static u_char
is_buzz (int num)
{
  return num % 5 == 0;
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
  int i = 0;
  for (i = 0; i < 100; i++)
    {
      fizzbuzz (i + 1);
    }
}
