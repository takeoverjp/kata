#include <stdio.h>
#include <sys/types.h>
#include <assert.h>

//#define TEST

static u_char
is_fizz (int num)
{
  if (num % 3 == 0)
    return 1;
  else
    return 0;
}

static u_char
is_buzz (int num)
{
  if (num % 5 == 0)
    return 1;
  else
    return 0;
}

static void
fizzbuzz (void)
{
  int i = 0;
  for (i = 0; i < 100; i++)
    {
      if (is_fizz (i) && is_buzz (i))
	fprintf (stderr, "FizzBuzz\n");
      else if (is_fizz (i))
	fprintf (stderr, "Fizz\n");
      else if (is_buzz (i))
	fprintf (stderr, "Buzz\n");
      else
	fprintf (stderr, "%d\n", i);
    }
}

static void
test_is_fizz (void)
{
  assert (is_fizz(-2) == 0);
  assert (is_fizz(1) == 0);
  assert (is_fizz(3) == 1);
  assert (is_fizz(0) == 1);
}

static void
test_is_buzz (void)
{
  assert (is_buzz(-2) == 0);
  assert (is_buzz(1) == 0);
  assert (is_buzz(5) == 1);
  assert (is_buzz(0) == 1);
}

static void
test (void)
{
  test_is_fizz ();
  test_is_buzz ();
}

int
main (void)
{
#if defined(TEST)
  test ();
#endif /* defined(TEST) */
  fizzbuzz ();
  return 0;
}
