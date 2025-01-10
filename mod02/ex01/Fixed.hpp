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
