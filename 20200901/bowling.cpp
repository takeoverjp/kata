#include <gtest/gtest.h>

class Frame final{
public:
  Frame(const int first, const int second = 0, const int third = 0)
    : m_score(0)
    , m_strike(false)
    , m_spare(false)
  {
    m_score = first + second + third;
    if (first == 10) {
      m_strike = true;
    } else if (m_score == 10){
      m_spare = true;
    }
  }
  int score(const int next = 0, const int next_next = 0) const {
    if (m_strike) {
      return m_score + next + next_next;
    }
    if (m_spare) {
      return m_score + next;
    }

    return m_score;
  }

private:
  int m_score;
  bool m_strike;
  bool m_spare;
};

class Game final{
public:
  Game() {
  }
  void addFrame(const Frame &frame) {
    m_frames.push_back(frame);
  }
  int score() {
    int sum = 0;
    for (const auto frame : m_frames) {
      sum += frame.score();
    }
    return sum;
  }
private:
  std::vector<Frame> m_frames;
};

TEST(BowlingTest, FrameNormal) {
  Frame f(1, 3);
  ASSERT_EQ(4, f.score());
  ASSERT_EQ(4, f.score(3));
  ASSERT_EQ(4, f.score(3, 5));
}

TEST(BowlingTest, FrameSpare) {
  Frame f(1, 9);
  ASSERT_EQ(10, f.score());
  ASSERT_EQ(13, f.score(3));
  ASSERT_EQ(13, f.score(3, 5));
}

TEST(BowlingTest, FrameStrike) {
  Frame f(10);
  ASSERT_EQ(10, f.score());
  ASSERT_EQ(13, f.score(3));
  ASSERT_EQ(18, f.score(3, 5));
}

TEST(BowlingTest, GameNormal) {
  Game g;
  g.addFrame(Frame(1, 1));

  ASSERT_EQ(2, g.score());
}

TEST(BowlingTest, GameNormalMultiFrames) {
  Game g;
  g.addFrame(Frame(1, 2));
  g.addFrame(Frame(3, 4));

  ASSERT_EQ(10, g.score());
}

TEST(BowlingTest, GameSpare) {
  Game g;
  g.addFrame(Frame(3, 7));
  g.addFrame(Frame(3, 4));

  ASSERT_EQ(20, g.score());
}
