#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called\n";
  value = 0;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called\n";
  this->value = value << fBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called\n";
  this->value = roundf(value * (1 << fBits));
}

Fixed::~Fixed(void) { std::cout << "Deconstructor called\n"; }

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called\n";
  this->value = f.value;
}

Fixed &Fixed::operator=(const Fixed &f) {
  std::cout << "Copy assignment operator called\n";
  if (this == &f)
    return *this;
  this->value = f.value;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  value = raw;
}

float Fixed::toFloat(void) const { return (float)value / (1 << fBits); }

int Fixed::toInt(void) const { return value >> fBits; }

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
  return out << f.toFloat();
}
