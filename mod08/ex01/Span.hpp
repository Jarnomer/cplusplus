#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <vector>

class Span {
private:
  unsigned int n; // size
  std::vector<int> vec;

public: // constructrors
  Span(void) = delete;
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);

public: // deconstructor
  ~Span(void);

public: // methods
  void addNumber(int number);
  void addNumbers(unsigned int count);
  int shortestSpan(void);
  int longestSpan(void);
};
