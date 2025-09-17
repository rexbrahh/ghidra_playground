// cpp_vtable.cpp
#include <iostream>
struct Base {
  virtual void hello() { std::cout << "Base\n"; }
  virtual ~Base() {}
};
struct Derived : Base {
  void hello() override { std::cout << "Derived secret: VTABLE_FLAG\n"; }
};

int main() {
  Base *b = new Derived();
  b->hello();
  delete b;
  return 0;
}
