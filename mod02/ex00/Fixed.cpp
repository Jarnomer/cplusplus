#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) { std::cout << "Default constructor called\n"; }

Fixed::~Fixed(void) { std::cout << "Deconstructor called\n"; }

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called\n";
  value = f.value;
}

Fixed &Fixed::operator=(const Fixed &f) {
  std::cout << "Copy assignment operator called\n";
  if (this == &f)
    return *this;
  value = f.value;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function\n";
  value = raw;
}
