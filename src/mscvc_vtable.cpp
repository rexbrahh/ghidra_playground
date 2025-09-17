// msvc_vtable.cpp
#include <iostream>
struct Base {
  virtual const char *who() { return "Base"; }
  virtual ~Base() {}
};
struct Secret : Base {
  const char *who() override { return "MSVC-SECRET"; }
};

int main() {
  Base *b = new Secret();
  std::cout << b->who() << std::endl;
  delete b;
  return 0;
}
