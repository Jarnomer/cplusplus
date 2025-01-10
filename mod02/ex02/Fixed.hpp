#pragma once

#include <cmath>
#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &f);
  Fixed &operator=(const Fixed &f);
  ~Fixed(void);

public:
  bool operator==(const Fixed &f) const;
  bool operator!=(const Fixed &f) const;
  bool operator<=(const Fixed &f) const;
  bool operator>=(const Fixed &f) const;
  bool operator<(const Fixed &f) const;
  bool operator>(const Fixed &f) const;

public:
  Fixed operator+(const Fixed &f) const;
  Fixed operator-(const Fixed &f) const;
  Fixed operator*(const Fixed &f) const;
  Fixed operator/(const Fixed &f) const;

public:
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

public:
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

public:
  int getRawBits(void) const;
  void setRawBits(int const raw);

public:
  float toFloat(void) const;
  int toInt(void) const;

private:
  int value;
  static const int fBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
