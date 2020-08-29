#include <iostream>
#include <gtest/gtest.h>

class Options final {
public:
  Options(const int argc, const char* const argv[]) :
    is_logging(false),
    port(0)
  {
    for (int i = 1; i < argc && argv[i]; i++)
      {
        const char* const opt = argv[i];
        if (opt[0] == '-')
          {
            switch (opt[1])
              {
              case 'l':
                is_logging = true;
                break;
              case 'p':
                if (i + 1 < argc)
                  {
                    i++;
                    port = strtol(argv[i], NULL, 10);
                  }
                break;
              case 'd':
                if (i + 1 < argc)
                  {
                    i++;
                    dir = std::string(argv[i]);
                  }
                break;
              default:
                std::cerr << "Unknown option(-" << opt[1] << ")"  << std::endl;
                break;
              }
          }
      }
  }

  friend std::ostream& operator<<(std::ostream& os, const Options &opts) {
    os << "is_logging = " << opts.is_logging << std::endl;
    os << "port = " << opts.port << std::endl;
    os << "dir = " << opts.dir << std::endl;
    return os;
  }

  bool is_logging;
  long port;
  std::string dir;
};

TEST(OptionsTest, NoArg) {
  const char* const argv[] = {"exe", NULL};
  Options opts(1, argv);

  EXPECT_FALSE(opts.is_logging);
  EXPECT_EQ(opts.port, 0);
  EXPECT_EQ(opts.dir, "");
}

TEST(OptionsTest, LoggingOption) {
  const char* const argv[] = {"exe", "-l", NULL};
  Options opts(2, argv);

  EXPECT_TRUE(opts.is_logging);
  EXPECT_EQ(opts.port, 0);
  EXPECT_EQ(opts.dir, "");
}

TEST(OptionsTest, MultiOptions) {
  const char* const argv[] = {"exe", "-p", "8080", "-l", NULL};
  Options opts(4, argv);

  EXPECT_TRUE(opts.is_logging);
  EXPECT_EQ(opts.port, 8080);
  EXPECT_EQ(opts.dir, "");
}

TEST(OptionsTest, AllOptions) {
  const char* const argv[] = {"exe", "-l", "-p", "8080", "-d", "/usr/logs", NULL};
  Options opts(6, argv);

  EXPECT_TRUE(opts.is_logging);
  EXPECT_EQ(opts.port, 8080);
  EXPECT_EQ(opts.dir, "/usr/logs");
}
