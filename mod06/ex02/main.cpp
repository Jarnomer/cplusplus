#include "Base.hpp"

int main(void) {
  int count = 5;
  for (int i = 0; i < count; i++) {
    Base *ptr = Base::generate();
    Base::identify(ptr);
    Base::identify(*ptr);
    delete ptr;
    std::cout << "\n";
  }
  Base::identify(nullptr);
  return 0;
}
