#include "Brain.hpp"

const unsigned int Brain::limit;

Brain::Brain(void) { std::cout << "Brain constructor called\n"; }

Brain::~Brain(void) { std::cout << "Brain deconstructor called\n"; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain copy constructor called\n";
  *this = other;
}

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain copy assignment operator called\n";
  if (this != &other) {
    for (unsigned int i = 0; i < limit; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

void Brain::setIdea(unsigned int index, std::string idea) {
  if (index >= limit) {
    std::cout << "Idea out of brain capacity\n";
    return;
  } else {
    ideas[index] = idea;
  }
}

std::string Brain::getIdea(unsigned int index) const {
  if (index >= limit) {
    std::cout << "Idea out of brain capacity\n";
    return {};
  } else {
    return ideas[index];
  }
}
