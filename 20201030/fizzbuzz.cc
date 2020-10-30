#include <iostream>

class FizzBuzz
{
private:
  int count_;
public:
  FizzBuzz();
  ~FizzBuzz();
  std::string CountUp();
};

FizzBuzz::FizzBuzz() : count_(0)
{
}

FizzBuzz::~FizzBuzz()
{
}

std::string FizzBuzz::CountUp() {
  count_++;
  if (count_ % 15 == 0) {
    return "FizzBuzz";
  } else if (count_ % 3 == 0) {
    return "Fizz";
  } else if (count_ % 5 == 0) {
    return "Buzz";
  } else {
    return std::to_string(count_);
  }
}

int
main (void) {
  FizzBuzz fb;
  for (int i = 0; i < 100; i++) {
    std::cout << fb.CountUp() << std::endl;
  }
  return 0;
}