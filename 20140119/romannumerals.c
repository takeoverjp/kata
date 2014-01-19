#include <stdio.h>
#include <limits.h>
#include <errno.h>

static int
num2rom (long num, char *rom, int rom_size)
{
  int index = 0;
  int i = 0;

  while (num >= 10)
    {
      rom[index++] = 'X';
      num -= 10;
    }

  if (num == 9)
    {
      rom[index++] = 'I';
      rom[index++] = 'X';
      num -= 9;
    }

  if (num >= 5)
    {
      rom[index++] = 'V';
      num -= 5;
    }

  if (num == 4)
    {
      rom[index++] = 'I';
      rom[index++] = 'V';
      num -= 4;
    }

  while (num > 0)
    {
      rom[index++] = 'I';
      num -= 1;
    }

  return index;
}

int
main (void)
{
  char str[80] = {0};
  char rom[80] = {0};
  long num = 0;

  printf ("Num : ");
  if (fgets (str, sizeof(str), stdin) == NULL)
    perror ("fgets");

  errno = 0;
  num = strtol (str, NULL, 10);
  if (num == 0 && errno == EINVAL)
    {
      fprintf (stderr, "Please input valid digit num.\n");
      return 1;
    }
  else if ((num == LONG_MAX || num == LONG_MIN) && errno == ERANGE)
    {
      fprintf (stderr, "Too large or too small.\n");
      return 1;
    }

  num2rom (num, rom, sizeof(rom));

  printf ("%ld -> %s\n", num, rom);

  return 0;
}
