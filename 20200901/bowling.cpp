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
    m_pins.push_back(first);
    if (second)
      m_pins.push_back(second);
    if (third)
      m_pins.push_back(third);
  }
  std::vector<int> pins() {
    return m_pins;
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
  std::vector<int> m_pins;
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
    for (u_int i = 0; i < m_frames.size(); i++) {
      int next = 0;
      int next_next = 0;
      if (i < m_frames.size() - 1) {
        std::vector<int> pins = m_frames[i+1].pins();
        next = pins[0];
        if (pins.size() >= 2) {
          next_next = pins[1];
        } else if (i < m_frames.size() - 2) {
          std::vector<int> pins = m_frames[i+2].pins();
          next_next = pins[0];
        }
      }
      sum += m_frames[i].score(next, next_next);
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

TEST(BowlingTest, GameStrike) {
  Game g;
  g.addFrame(Frame(10));
  g.addFrame(Frame(3, 4));

  ASSERT_EQ(24, g.score());
}

TEST(BowlingTest, GameTurkey) {
  Game g;
  g.addFrame(Frame(10));
  g.addFrame(Frame(10));
  g.addFrame(Frame(10));

  ASSERT_EQ(60, g.score());
}

TEST(BowlingTest, GameLastSpare) {
  Game g;
  for (int i = 0; i < 9; i++)
    g.addFrame(Frame(10));
  g.addFrame(Frame(1, 9, 10));

  ASSERT_EQ(300, g.score());
}

TEST(BowlingTest, GameFullScore) {
  Game g;
  for (int i = 0; i < 9; i++)
    g.addFrame(Frame(10));
  g.addFrame(Frame(10, 10, 10));

  ASSERT_EQ(300, g.score());
}
