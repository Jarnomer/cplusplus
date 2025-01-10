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

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called\n";
  value = f.value;
}

Fixed::~Fixed(void) { std::cout << "Deconstructor called\n"; }

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
  std::cout << "setRawBits member function called\n";
  value = raw;
}

float Fixed::toFloat(void) const { return (float)value / (1 << fBits); }

int Fixed::toInt(void) const { return value >> fBits; }

bool Fixed::operator==(const Fixed &f) const { return value == f.value; }

bool Fixed::operator!=(const Fixed &f) const { return value != f.value; }

bool Fixed::operator<=(const Fixed &f) const { return value <= f.value; }

bool Fixed::operator>=(const Fixed &f) const { return value >= f.value; }

bool Fixed::operator<(const Fixed &f) const { return value < f.value; }

bool Fixed::operator>(const Fixed &f) const { return value > f.value; }

Fixed Fixed::operator+(const Fixed &f) const {
  Fixed temp;
  temp.setRawBits(value + f.value);
  return temp;
}

Fixed Fixed::operator-(const Fixed &f) const {
  Fixed temp;
  temp.setRawBits(value - f.value);
  return temp;
}

Fixed Fixed::operator*(const Fixed &f) const {
  Fixed temp;
  temp.setRawBits((value * f.value) >> fBits);
  return temp;
}

Fixed Fixed::operator/(const Fixed &f) const {
  Fixed temp;
  temp.setRawBits((value << fBits) / f.value);
  return temp;
}

Fixed &Fixed::operator++(void) {
  this->value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  this->value++;
  return temp;
}

Fixed &Fixed::operator--(void) {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  this->value--;
  return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
  return out << f.toFloat();
}
