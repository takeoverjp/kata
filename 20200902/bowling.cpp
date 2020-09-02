#include <gtest/gtest.h>

class Frame final {
 public:
  Frame()
    : m_throwNum(1)
    , m_first(10)
    , m_second(0)
    , m_third(0)
    , m_strike(true)
    , m_spare(false)
  {
  }

  Frame(const int first, const int second)
    : m_throwNum(2)
    , m_first(first)
    , m_second(second)
    , m_third(0)
    , m_strike(false)
    , m_spare(false)
  {
    if (m_first + m_second == 10)
      m_spare = true;
  }


Frame(const int first, const int second, const int third)
    : m_throwNum(3)
    , m_first(first)
    , m_second(second)
    , m_third(third)
    , m_strike(false)
    , m_spare(false)
  {
  }

  int score(const int next, const int next_next) const {
    const int base = m_first + m_second + m_third;
    if (m_strike)
      return base + next + next_next;
    if (m_spare)
      return base + next;
    return base;
  }
  int first() const {
    return m_first;
  }
  int second() const {
    return m_second;
  }
  int third() const {
    return m_third;
  }
  int throwNum() const {
    return m_throwNum;
  }

 private:
  const int m_throwNum;
  const int m_first;
  const int m_second;
  const int m_third;
  bool m_strike;
  bool m_spare;
};

TEST(FrameTest, Normal) {
  Frame f(1, 2);
  ASSERT_EQ(3, f.score(3, 4));
}

TEST(FrameTest, Spare) {
  Frame f(1, 9);
  ASSERT_EQ(13, f.score(3, 4));
}

TEST(FrameTest, Strike) {
  Frame f;
  ASSERT_EQ(17, f.score(3, 4));
}

class Game final {
public:
  explicit Game() {};
  void addFrame(const Frame& frame) {
    m_frames.push_back(frame);
  }
  int score() {
    int score = 0;
    for (u_int i = 0; i < m_frames.size(); i++) {
      int next = 0;
      int next_next = 0;
      const Frame &frame = m_frames[i];
      if (i < m_frames.size() - 1) {
        next = m_frames[i+1].first();
        if (m_frames[i+1].throwNum() > 1)
          next_next = m_frames[i+1].second();
        else {
          if (i < m_frames.size() - 2)
            next_next = m_frames[i+2].first();
        }
      }
      score += frame.score(next, next_next);
    }
    return score;
  }

private:
  std::vector<Frame> m_frames;
};

TEST(GameTest, Normal) {
  Game g;
  g.addFrame(Frame(1, 2));
  ASSERT_EQ(3, g.score());
}

TEST(GameTest, MultiNormal) {
  Game g;
  g.addFrame(Frame(1, 2));
  g.addFrame(Frame(3, 4));
  ASSERT_EQ(10, g.score());
}

TEST(GameTest, Spare) {
  Game g;
  g.addFrame(Frame(8, 2));
  g.addFrame(Frame(3, 4));
  ASSERT_EQ(20, g.score());
}

TEST(GameTest, Strike) {
  Game g;
  g.addFrame(Frame());
  g.addFrame(Frame(3, 4));
  ASSERT_EQ(24, g.score());
}

TEST(GameTest, DoubleStrike) {
  Game g;
  g.addFrame(Frame());
  g.addFrame(Frame());
  g.addFrame(Frame(3, 4));
  ASSERT_EQ(47, g.score());
}

TEST(GameTest, FullScore) {
  Game g;
  for (int i = 0; i < 9; i++)
    g.addFrame(Frame());
  g.addFrame(Frame(10, 10, 10));
  ASSERT_EQ(300, g.score());
}
