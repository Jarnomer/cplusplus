#pragma once

#include <cctype>
#include <iostream>
#include <limits>
#include <stack>
#include <stdexcept>

class RPN {
private:
  static std::stack<int> stack;
  static std::string number;
  static const std::string tokens;

public:
  RPN(void) = delete;
  RPN(const RPN &other) = delete;
  RPN &operator=(const RPN &other) = delete;
  ~RPN(void) = delete;

  static void calculate(const std::string &expression);

private:
  static void appendStack(const std::string &value);
  static bool isValidOperation(char c);
  static void performCalculation(char c);
  static int performOperation(int a, int b, char op);
  static bool willOverflow(int a, int b, char op);
  static void printResult(void);
};
