#pragma once

#include <cctype>
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>

enum class ScalarType { Invalid, Char, Int, Float, Double };

class ScalarConverter {
public:
  ScalarConverter(void) = delete;
  ScalarConverter(const ScalarConverter &other) = delete;
  ScalarConverter &operator=(const ScalarConverter &other) = delete;
  ~ScalarConverter(void) = delete;

  static void convert(std::string input);
};
