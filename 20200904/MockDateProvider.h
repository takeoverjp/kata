#include <gmock/gmock.h>

class MockDateProvider : public DateProvider {
 public:
  MOCK_METHOD0(getNow, time_t());
};
