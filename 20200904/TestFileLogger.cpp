#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include <FileLogger.h>

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
      whole += line;
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

  ASSERT_EQ("2020-09-04 16:10:06 test", getLog());
}

TEST_F(TestFileLogger, OneLine) {
  MockDateProvider dp;
  EXPECT_CALL(dp, getNow())
    .WillOnce(Return(1599235806));

  FileLogger fl(dp);
  fl.Log("test");

  ASSERT_EQ("2020-09-04 16:10:06 test", getLog());
}
