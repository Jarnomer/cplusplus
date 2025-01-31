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
  ~Span(void);

public: // methods
  void addNumber(int number);
  int shortestSpan(void);
  int longestSpan(void);

public: // addNumbers template
  template<typename It> void addNumbers(It begin, It end) {
    for (auto it = begin; it != end; ++it) {
      addNumber(*it);
    }
  }
};
