#include <iostream>
#include <gtest/gtest.h>

int
binchop (int target, const std::vector<int> &vec)
{
  if (vec.size() == 0)
    return -1;

  if (vec.size() == 1) {
    if (vec[0] == target)
      return 0;
    else
      return -1;
  }

  int center = vec.size() / 2;

  if (target < vec[center]) {
    return binchop(target, std::vector<int>(vec.begin(), vec.begin() + center));
  } else {
    int ret = binchop(target, std::vector<int>(vec.begin() + center, vec.end()));
    return (ret < 0) ? -1 : (center + ret);
  }
}


TEST(TestBinchop, NotFoundForZeroLengthVector)
{
  ASSERT_EQ(-1, binchop(1, std::vector<int>()));
}

TEST(TestBinchop, FoundForOneLengthVector)
{
  const std::vector<int> vec = {1};
  ASSERT_EQ(0, binchop(1, vec));
}

TEST(TestBinchop, NotFoundForOneLengthVector)
{
  const std::vector<int> vec = {1};
  ASSERT_EQ(-1, binchop(3, vec));
}

TEST(TestBinchop, FoundForThreeLengthVector)
{
  const std::vector<int> vec = {1, 3, 5};
  ASSERT_EQ(0, binchop(1, vec));
  ASSERT_EQ(1, binchop(3, vec));
  ASSERT_EQ(2, binchop(5, vec));
}

TEST(TestBinchop, NotFoundForThreeLengthVector)
{
  const std::vector<int> vec = {2, 4, 6};
  ASSERT_EQ(-1, binchop(1, vec));
  ASSERT_EQ(-1, binchop(3, vec));
  ASSERT_EQ(-1, binchop(5, vec));
}

TEST(TestBinchop, FoundForFourLengthVector)
{
  const std::vector<int> vec = {1, 3, 5, 7};
  ASSERT_EQ(0, binchop(1, vec));
  ASSERT_EQ(1, binchop(3, vec));
  ASSERT_EQ(2, binchop(5, vec));
  ASSERT_EQ(3, binchop(7, vec));
}

TEST(TestBinchop, NotFoundForFourLengthVector)
{
  const std::vector<int> vec = {2, 4, 6, 8};
  ASSERT_EQ(-1, binchop(1, vec));
  ASSERT_EQ(-1, binchop(3, vec));
  ASSERT_EQ(-1, binchop(5, vec));
  ASSERT_EQ(-1, binchop(7, vec));
}
