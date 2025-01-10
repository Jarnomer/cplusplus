#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
  std::cout << type << " constructor called\n";
  brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
  std::cout << type << " constructor called\n";
  brain = new Brain();
}

Dog::~Dog(void) {
  std::cout << type << " deconstructor called\n";
  delete brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << type << " copy constructor called\n";
  type = other.type;
  brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << type << " copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  return *this;
}

void Dog::makeSound(void) const { std::cout << type << " barks...\n"; }

void Dog::setIdea(unsigned int index, std::string idea) {
  if (index >= 100) {
    std::cout << "Idea out of brain capacity\n";
    return;
  } else {
    brain->setIdea(index, idea);
  }
}

std::string Dog::getIdea(unsigned int index) const {
  if (index >= 100) {
    std::cout << "Idea out of brain capacity\n";
    return {};
  } else {
    return brain->getIdea(index);
  }
}
