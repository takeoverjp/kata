#include <stdio.h>

static void
print_diamond_line(const char chr, const char end)
{
  int offset = chr - 'A';

  printf ("%*c", end - chr + 2, chr);

  if (chr == 'A')
    {
      printf("\n");
      return;
    }

  printf ("%*c\n", 2 * offset, chr);
}

void
diamond(const char end)
{
  for (int chr = 'A'; chr <= end; chr++)
    print_diamond_line(chr, end);

  for (int chr = end - 1; chr >= 'A'; chr--)
    print_diamond_line(chr, end);
}

int
main (void)
{
  diamond('A');
  diamond('B');
  diamond('C');
  diamond('D');
  diamond('E');
  return 0;
}
