#include <iostream>

class Base {
public:
  Base() {}
  ~Base() {
    std::cout << "~Base" << std::endl;
  }
};

class Derived: public Base {
public:
  Derived() {}
  ~Derived(){
    std::cout << "~Derived" << std::endl;
  }
};

class VirtBase {
public:
  VirtBase() {}
  virtual ~VirtBase() {
    std::cout << "~Base" << std::endl;
  }
};

class VirtDerived: public VirtBase {
public:
  VirtDerived() {}
  virtual ~VirtDerived() {
    std::cout << "~Derived" << std::endl;
  }
};

int
main ()
{
  std::cout << "Non-Virtual Non-Polymorphic: " << std::endl;
  auto d = new Derived();
  delete d;

  std::cout << "Non-Virtual Polymorphic: " << std::endl;
  auto b = static_cast<Base*>(new Derived());
  delete b;

  std::cout << "Virtual Non-Polymorphic: " << std::endl;
  auto vd = new VirtDerived();
  delete vd;

  std::cout << "Virtual Polymorphic: " << std::endl;
  auto vb = static_cast<VirtBase*>(new VirtDerived());
  delete vb;


  std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;
  std::cout << "sizeof(Derived) = " << sizeof(Derived) << std::endl;
  std::cout << "sizeof(VirtBase) = " << sizeof(VirtBase) << std::endl;
  std::cout << "sizeof(VirtDerived) = " << sizeof(VirtDerived) << std::endl;

  return 0;
}
