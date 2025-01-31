#include "Span.hpp"

int main(void) {
  try {
    {
      Span span = Span(5);
      span.addNumber(6);
      span.addNumber(3);
      span.addNumber(17);
      span.addNumber(9);
      span.addNumber(11);
      std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
      std::cout << "Longest Span: " << span.longestSpan() << "\n\n";
    }
    {
      std::cout << std::endl;
      Span span(10);
      std::vector<int> vec = {6, 3, 17, 9, 11};
      span.addNumbers(vec.begin(), vec.end());
      std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
      std::cout << "Longest Span: " << span.longestSpan() << "\n\n";
      // std::vector<int> vec2 = {56, 22, 123, 9999, 566, 234, 63, 1};
      // span.addNumbers(vec2.begin(), vec2.end()); // trigger exception
    }
    {
      std::cout << std::endl;
      Span span(3);
      span.addNumber(-10);
      span.addNumber(0);
      span.addNumber(21);
      std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
      std::cout << "Longest Span: " << span.longestSpan() << "\n";
      std::cout << std::endl;
      // span.addNumber(42); // trigger exception
    }
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << "\n";
  }
  return 0;
}
