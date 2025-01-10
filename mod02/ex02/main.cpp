#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << "\nIncrement operators\n\n";
  std::cout << "a: " << a << "\n";
  std::cout << "a: " << ++a << "\n";
  std::cout << "a: " << a << "\n";
  std::cout << "a: " << a++ << "\n";
  std::cout << "a: " << a << "\n";

  std::cout << "b: " << b << "\n";

  std::cout << "\nComparison operators\n\n";
  std::cout << "Is a: " << a << " == b: " << b << " -> " << (a == b) << "\n";
  std::cout << "Is a: " << a << " != b: " << b << " -> " << (a != b) << "\n";
  std::cout << "Is a: " << a << " <= b: " << b << " -> " << (a <= b) << "\n";
  std::cout << "Is a: " << a << " < b: " << b << " -> " << (a < b) << "\n";
  std::cout << "Is a: " << a << " >= b: " << b << " -> " << (a >= b) << "\n";
  std::cout << "Is a: " << a << " > b: " << b << " -> " << (a > b) << "\n";

  std::cout << "\nArithmetic operators\n\n";
  std::cout << "What is b: " << b << " - 3.0f ?\n" << (b - 3.0f) << "\n\n";
  std::cout << "\nWhat is b: " << b << " + 0.3f ?\n" << (b + 0.3f) << "\n\n";
  std::cout << "\nWhat is b: " << b << " / 2 ?\n" << (b / 2) << "\n\n";
  std::cout << "\nWhat is b: " << b << " * 2 ?\n" << (b * 2) << "\n\n";

  a = 0.0f;
  std::cout << "\nDecrement operators\n\n";
  std::cout << "a: " << a << "\n";
  std::cout << "a: " << --a << "\n";
  std::cout << "a: " << a << "\n";
  std::cout << "a: " << a-- << "\n";
  std::cout << "a: " << a << "\n";

  std::cout << "\nMin/Max operators\n\n";
  std::cout << "Max of a: " << a << " b: " << b << " -> " << Fixed::max(a, b) << "\n";
  std::cout << "Min of a: " << a << " b: " << b << " -> " << Fixed::min(a, b) << "\n";
  return 0;
}
