#include <Span.hpp>

Span::Span(unsigned int n) : n(n) {
  std::cout << "Parametric constructor called\n";
}

Span::Span(const Span &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

Span &Span::operator=(const Span &other) {
  std::cout << "Copy assignment called\n";
  if (this != &other) {
    this->n = other.n;
    this->vec = other.vec;
  }
  return *this;
}

Span::~Span(void) { std::cout << "Deconstructor called\n"; }

void Span::addNumber(int number) {
  if (vec.size() == n) {
    throw std::out_of_range("Max size reached!");
  } else {
    vec.push_back(number);
  }
}

void Span::addNumbers(unsigned int count) {
  if (vec.size() + count > n) {
    throw std::runtime_error("Max size reached!");
  } else {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10000, 10000);
    for (size_t i = 0; i < count; ++i) {
      addNumber(dist(gen));
    }
  }
}

int Span::shortestSpan(void) {
  if (vec.size() <= 1) {
    throw std::runtime_error("No enough elements!");
  } else {
    std::vector<int> sorted = vec;
    std::sort(sorted.begin(), sorted.end());
    int min = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); i++) {
      min = std::min(min, sorted[i] - sorted[i - 1]);
    }
    return min;
  }
}

int Span::longestSpan(void) {
  if (vec.size() <= 1) {
    throw std::runtime_error("No enough elements!");
  } else {
    auto [min, max] = std::minmax_element(vec.begin(), vec.end());
    return *max - *min;
  }
}
