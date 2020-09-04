#include <iostream>
#include <fstream>
#include <time.h>

class DateProvider {
public:
  DateProvider() {};
  virtual ~DateProvider() {};
  virtual time_t getNow() {
    return time(NULL);
  };
};

class FileLogger final {
public:
  FileLogger(DateProvider &dp)
    : m_DateProvider(dp)
    , m_fname("test.log")
    , m_ostream(m_fname)
  {
  }
  ~FileLogger() {}
  void Log(const std::string& message) {
    struct tm tm;
    const time_t now = m_DateProvider.getNow();
    gmtime_r(&now, &tm);
    char timestamp[1024];
    sprintf (timestamp, "%04d-%02d-%02d %02d:%02d:%02d ",
             tm.tm_year + 1900,
             tm.tm_mon + 1,
             tm.tm_mday,
             tm.tm_hour,
             tm.tm_min,
             tm.tm_sec);
    m_ostream << std::string(timestamp) << message << std::endl;
  }

private:
  DateProvider& m_DateProvider;
  const std::string m_fname;
  std::ofstream m_ostream;
};


#include <gtest/gtest.h>
#include "MockDateProvider.h"
using ::testing::Return;

class TestFileLogger: public ::testing::Test {
protected:
  virtual void SetUp() {
  }
  virtual void TearDown() {
    ::unlink("test.log");
  }

  std::string getLog() {
    std::string whole;
    std::string line;
    std::ifstream ifs("test.log");
    while (getline(ifs, line)){
      whole += line + "\n";
    }
    return whole;
  }
};

TEST_F(TestFileLogger, OneLine) {
  MockDateProvider dp;
  EXPECT_CALL(dp, getNow())
    .WillOnce(Return(1599235806));

  FileLogger fl(dp);
  fl.Log("test");

  ASSERT_EQ("2020-09-04 16:10:06 test\n", getLog());
}

TEST_F(TestFileLogger, OneTwoLine) {
  MockDateProvider dp;
  EXPECT_CALL(dp, getNow())
    .WillOnce(Return(1599235806))
    .WillOnce(Return(1599235807));

  FileLogger fl(dp);
  fl.Log("test");
  fl.Log("test2");

  ASSERT_EQ("2020-09-04 16:10:06 test\n"
            "2020-09-04 16:10:07 test2\n", getLog());
}
