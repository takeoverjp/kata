#include <stdio.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
  char c;
  while ((c = getopt(argc, argv, "lp:d:")) != -1)
    {
      switch (c)
	{
	case 'l':
	  fprintf (stderr, "-l option\n");
	  break;
	case 'p':
	  fprintf (stderr, "-p option (%s)\n", optarg);
	  break;
	case 'd':
	  fprintf (stderr, "-d option (%s)\n", optarg);
	  break;
	default:
	  fprintf (stderr, "Unknown option\n");
	  break;
	}
    }
  return 0;
}
