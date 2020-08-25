#include <iostream>
#include <gtest/gtest.h>

int
chop(int target, auto &array)
{
  int start = 0;
  if (!array.size())
    return -1;

  int end = array.size() - 1;

  while (start < end) {
    int center = (start + end) / 2;

    if (array[center] == target)
      return center;

    if (array[center] < target) {
      if (start == center) {
        start++;
        continue;
      }
      start = center;
    }

    if (array[center] > target) {
      if (end == center) {
        end--;
        continue;
      }
      end = center;
    }
  }

  if (array[start] == target)
    return start;

  return -1;
}

class ChopTest : public ::testing::Test {
};

TEST(ChopTest, ReturnNegativeForZeroLengthArray) {
  std::array<int, 0>array({});
  ASSERT_EQ (-1, chop(3, array));
}

TEST(ChopTest, ReturnNegativeForOneLengthArrayAndNotFound) {
  std::array<int, 1>array({1});
  ASSERT_EQ (-1, chop(3, array));
}

TEST(ChopTest, ReturnIndexOneLengthArrayAndFound) {
  std::array<int, 1>array({1});
  ASSERT_EQ (0, chop(1, array));
}

TEST(ChopTest, FoundInThreeLengthArray) {
  std::array<int, 3>array({1, 3, 5});
  ASSERT_EQ (0, chop(1, array));
  ASSERT_EQ (1, chop(3, array));
  ASSERT_EQ (2, chop(5, array));
}

TEST(ChopTest, NotFoundInThreeLengthArray) {
  std::array<int, 3>array({1, 3, 5});
  ASSERT_EQ (-1, chop(0, array));
  ASSERT_EQ (-1, chop(2, array));
  ASSERT_EQ (-1, chop(4, array));
  ASSERT_EQ (-1, chop(6, array));
}

TEST(ChopTest, FoundIn4LengthArray) {
  std::array<int, 4>array({1, 3, 5, 7});
  ASSERT_EQ (0, chop(1, array));
  ASSERT_EQ (1, chop(3, array));
  ASSERT_EQ (2, chop(5, array));
  ASSERT_EQ (3, chop(7, array));
}

TEST(ChopTest, NotFoundIn4LengthArray) {
  std::array<int, 4>array({1, 3, 5, 7});
  ASSERT_EQ (-1, chop(0, array));
  ASSERT_EQ (-1, chop(2, array));
  ASSERT_EQ (-1, chop(4, array));
  ASSERT_EQ (-1, chop(6, array));
  ASSERT_EQ (-1, chop(8, array));
}
