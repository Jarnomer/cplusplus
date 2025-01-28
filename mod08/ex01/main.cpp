#include <Span.hpp>

int main(void) {
  try {
    {
      Span span = Span(5);
      span.addNumber(6);
      span.addNumber(3);
      span.addNumber(17);
      span.addNumber(9);
      span.addNumber(11);
      std::cout << "Subject result\n";
      std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
      std::cout << "Longest Span: " << span.longestSpan() << "\n\n";
    }
    {
      std::cout << std::endl;
      Span span(10);
      span.addNumbers(5);
      std::cout << "Randomized result\n";
      std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
      std::cout << "Longest Span: " << span.longestSpan() << "\n\n";
    }
    {
      std::cout << std::endl;
      Span span(3);
      span.addNumber(-10);
      span.addNumber(0);
      span.addNumber(21);
      std::cout << "Predictable result\n";
      std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
      std::cout << "Longest Span: " << span.longestSpan() << "\n";
      std::cout << std::endl;
      span.addNumber(42); // triggers exception
    }
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << "\n";
  }
  return 0;
}
