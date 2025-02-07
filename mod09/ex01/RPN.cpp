#include "RPN.hpp"

std::stack<int> RPN::stack;
std::string RPN::number;
const std::string RPN::operands = "+-/*";

void RPN::calculate(const std::string &expression) {
  for (char c : expression) {
    if (std::isdigit(c)) {
      number += c;
    } else if (std::isspace(c)) {
      appendStack(number);
      number.clear();
    } else if (isValidOperation(c)) {
      performCalculation(c);
    }
  }
  printResult();
}

void RPN::appendStack(const std::string &value) {
  if (!number.empty()) {
    int result = std::stoi(value);
    if (result < 0 || result > 9) {
      throw std::invalid_argument("Syntax error");
    } else {
      stack.push(result);
    }
  }
}

bool RPN::isValidOperation(char c) {
  if (operands.find(c) == std::string::npos || stack.size() < 2) {
    throw std::invalid_argument("Syntax error");
  } else {
    return true;
  }
}

void RPN::performCalculation(char op) {
  int a, b, result;
  b = stack.top();
  stack.pop();
  a = stack.top();
  stack.pop();
  result = performOperation(a, b, op);
  stack.push(result);
}

int RPN::performOperation(int a, int b, char op) {
  if (willOverflow(a, b, op)) {
    throw std::overflow_error("Arithmetic overflow");
  }
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  default:
    throw std::invalid_argument("Syntax error");
  }
}

bool RPN::willOverflow(int a, int b, char op) {
  switch (op) {
    case '*':
      if (b > 0) {
        return (a > std::numeric_limits<int>::max() / b ||
                a < std::numeric_limits<int>::min() / b);
      } else if (b < 0) {
        return (a < std::numeric_limits<int>::max() / b ||
                a > std::numeric_limits<int>::min() / b);
      } else {
        return false;
      }
    case '+':
      if (b > 0) {
        return (a > std::numeric_limits<int>::max() - b);
      } else {
        return (a < std::numeric_limits<int>::min() - b);
      }
    case '-':
      if (b > 0) {
        return (a < std::numeric_limits<int>::min() + b);
      } else {
        return (a > std::numeric_limits<int>::max() + b);
      }
    case '/':
      return (b == 0 || (a == std::numeric_limits<int>::min() && b == -1));
    default:
      return false;
  }
}

void RPN::printResult(void) {
  if (!number.empty()) {
    appendStack(number);
  }
  if (stack.size() != 1) {
    throw std::invalid_argument("Syntax error");
  } else {
    std::cout << stack.top() << "\n";
  }
}
