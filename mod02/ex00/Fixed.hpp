#pragma once

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(const Fixed &f);
  Fixed &operator=(const Fixed &f);
  ~Fixed(void);

public:
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int value;
  static const int fBits = 8;
};
