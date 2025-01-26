#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "Base.hpp"

Base::~Base(void) { std::cout << "Base deconstuctor called\n"; }

Base *Base::generate() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 100);
  int rng = dist(gen) % 3;
  if (rng == 1) {
    return new A();
  } else if (!rng) {
    return new B();
  } else {
    return new C();
  }
}

void Base::identify(Base &p) { identify(&p); }

void Base::identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "A identified!\n";
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B identified!\n";
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C identified!\n";
  } else {
    std::cout << "Unknown type!\n";
  }
}
