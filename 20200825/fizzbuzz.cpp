#include <iostream>

class FizzBuzz final
{
public:
  explicit FizzBuzz(int i)
    : m_num(i)
  {
  }
  FizzBuzz() = delete;
  FizzBuzz(const FizzBuzz&) = delete;
  FizzBuzz& operator=(const FizzBuzz&) = delete;
  FizzBuzz(const FizzBuzz&&) = delete;
  FizzBuzz& operator=(const FizzBuzz&&) = delete;
  friend std::ostream& operator<<(std::ostream& os, const FizzBuzz& fb)
  {
    if (fb.m_num % 15 == 0)
      os << "FizzBuzz";
    else if (fb.m_num % 5 == 0)
      os << "Fizz";
    else if (fb.m_num % 5 == 0)
      os << "Buzz";
    else
      os << fb.m_num;
    return os;
  }

private:
  int m_num;
};

int
main (void)
{
  for (int i = 1; i <= 100; i++) {
    FizzBuzz fb(i);
    std::cout << fb << std::endl;
  }

  for (int i = 1; i <= 100; i++) {
    std::cout << FizzBuzz(i) << std::endl;
  }

#if 0
  FizzBuzz fb2(2);

  // Copy Constructor
  FizzBuzz fb3 = fb2;

  // Move Constructor
   FizzBuzz fb4 = FizzBuzz(1);

  // Copy Assignment Operator
  FizzBuzz fb5(5);
  fb5 = fb2;

  // Move Assignment Operator
  FizzBuzz fb6(6);
  fb6 = FizzBuzz(7);
#endif
  
  
  return 0;
}
