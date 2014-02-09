#include <stdio.h>

static void
fizzbuzz (int i, char *buf, int size)
{
  if (i % 15 == 0)
    snprintf (buf, size, "FizzBuzz");
  else if (i % 3 == 0)
    snprintf (buf, size, "Fizz");
  else if (i % 5 == 0)
    snprintf (buf, size, "Buzz");
  else
    snprintf (buf, size, "%d", i);
}

static void
map (void (*func) (int i, char *buf, int size), int array[], int array_size)
{
  int i = 0;

  for (i = 0; i < array_size; i++)
    {
      char buf[1024] = {0};
      func (array[i], buf, sizeof(buf));
      fprintf (stderr, "%s\n", buf);
    }
  return;
}

int
main(void)
{
  int array[100] = {1,2,3,4,5,6,7,8,9,10,
                    11,12,13,14,15,16,17,18,19,20,
                    21,22,23,24,25,26,27,28,29,30,
                    31,32,33,34,35,36,37,38,39,40,
                    41,42,43,44,45,46,47,48,49,50,
                    51,52,53,54,55,56,57,58,59,60,
                    61,62,63,64,65,66,67,68,69,70,
                    71,72,73,74,75,76,77,78,79,80,
                    81,82,83,84,85,86,87,88,89,90,
                    91,92,93,94,95,96,97,98,99,100};

  map (fizzbuzz, array, sizeof(array)/sizeof(array[0]));
  return 0;
}
