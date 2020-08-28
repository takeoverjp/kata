#include <gtest/gtest.h>

static std::string
diamondOneLine(const char chr, const char end) {
  std::string ret;

  for (int i = 0; i < end - chr; i++)
    ret += " ";
  ret += chr;

  if (chr == 'A')
    return ret;

  for (int i = 0; i < 2 * (chr - 'A') - 1; i++)
    ret += " ";

  ret += chr;

  return ret;
}

static std::string
diamond(const char end) {
  std::string ret;
  for (char c = 'A'; c <= end; c++) {
    ret += diamondOneLine(c, end) + '\n';
  }

  for (char c = end - 1; c >= 'A'; c--) {
    ret += diamondOneLine(c, end) + '\n';
  }

  return ret;
}

TEST(DiamondOneLineTest, A_for_A) {
  ASSERT_EQ(std::string("A"), diamondOneLine('A', 'A'));
}

TEST(DiamondOneLineTest, B) {
  ASSERT_EQ(std::string(" A"), diamondOneLine('A', 'B'));
  ASSERT_EQ(std::string("B B"), diamondOneLine('B', 'B'));
}

TEST(DiamondOneLineTest, C) {
  ASSERT_EQ(std::string("  A"), diamondOneLine('A', 'C'));
  ASSERT_EQ(std::string(" B B"), diamondOneLine('B', 'C'));
  ASSERT_EQ(std::string("C   C"), diamondOneLine('C', 'C'));
}

TEST(DiamondOneLineTest, D) {
  ASSERT_EQ(std::string("   A"), diamondOneLine('A', 'D'));
  ASSERT_EQ(std::string("  B B"), diamondOneLine('B', 'D'));
  ASSERT_EQ(std::string(" C   C"), diamondOneLine('C', 'D'));
  ASSERT_EQ(std::string("D     D"), diamondOneLine('D', 'D'));
}

TEST(DiamondTest, A) {
  ASSERT_EQ(std::string("A\n"), diamond('A'));
}

TEST(DiamondTest, B) {
  ASSERT_EQ(std::string(" A\n"
                        "B B\n"
                        " A\n"),
            diamond('B'));
}

TEST(DiamondTest, C) {
  ASSERT_EQ(std::string("  A\n"
                        " B B\n"
                        "C   C\n"
                        " B B\n"
                        "  A\n"),
            diamond('C'));
}

TEST(DiamondTest, D) {
  ASSERT_EQ(std::string("   A\n"
                        "  B B\n"
                        " C   C\n"
                        "D     D\n"
                        " C   C\n"
                        "  B B\n"
                        "   A\n"),
            diamond('D'));
}
