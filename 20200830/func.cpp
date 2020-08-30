#include <iostream>
#include <functional>

#if !defined(USE_LAMBDA)
static void
callback1()
{
  std::cout << "callback1 is called" << std::endl;
}
static void
callback2()
{
  std::cout << "callback2 is called" << std::endl;
}
#endif

static void
call(std::function<void()>callback) {
  callback();
}

int
main ()
{
#if defined(USE_LAMBDA)
  std::function<void()> callback1 = [](){
    std::cout << "callback1 is called" << std::endl;
  };
  std::function<void()> callback2 = [](){
    std::cout << "callback2 is called" << std::endl;
  };
#endif
  call(callback1);
  call(callback2);
  return 0;
}
