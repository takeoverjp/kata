#include <gtest/gtest.h>

class Options {
public:
  Options(const int argc, const char *const argv[])
    : m_log(false),
      m_port(0){
    for (int i = 1; i < argc && argv[i]; i++)
      {
        const char* const opt = argv[i];
        if (opt[0] == '-')
          {
            switch (opt[1])
              {
              case 'l':
                m_log = true;
                break;
              case 'p':
                if ((i < argc - 1) && argv[i+1])
                  {
                    m_port = strtol(argv[i+1], NULL, 10);
                    i++;
                  }
                break;
              case 'd':
                if ((i < argc - 1) && argv[i+1])
                  {
                    m_dir = argv[i+1];
                    i++;
                  }
                break;
              default:
                std::cerr << "Unknown option" << std::endl;
                break;
              }
          }
      }
  }
  bool log() {
    return m_log;
  }
  long port() {
    return m_port;
  }
  std::string dir() {
    return m_dir;
  }
private:
  bool m_log;
  long m_port;
  std::string m_dir;
};

TEST(ArgsTest, NoArg) {
  const char *const argv[] = {"exe", NULL};
  int argc = 0;
  for (argc = 0; argv[argc]; argc++);

  Options opt(argc, argv);

  ASSERT_FALSE(opt.log());
  ASSERT_EQ(0, opt.port());
  ASSERT_EQ("", opt.dir());
}

TEST(ArgsTest, LogOption) {
  const char *const argv[] = {"exe", "-l", NULL};
  int argc = 0;
  for (argc = 0; argv[argc]; argc++);

  Options opt(argc, argv);

  ASSERT_TRUE(opt.log());
  ASSERT_EQ(0, opt.port());
  ASSERT_EQ("", opt.dir());
}

TEST(ArgsTest, PortOption) {
  const char *const argv[] = {"exe", "-p", "8080", NULL};
  int argc = 0;
  for (argc = 0; argv[argc]; argc++);

  Options opt(argc, argv);

  ASSERT_FALSE(opt.log());
  ASSERT_EQ(8080, opt.port());
  ASSERT_EQ("", opt.dir());
}

TEST(ArgsTest, DirOption) {
  const char *const argv[] = {"exe", "-d", "/usr/debug", "-p", "8080", NULL};
  int argc = 0;
  for (argc = 0; argv[argc]; argc++);

  Options opt(argc, argv);

  ASSERT_FALSE(opt.log());
  ASSERT_EQ(8080, opt.port());
  ASSERT_EQ("/usr/debug", opt.dir());
}
