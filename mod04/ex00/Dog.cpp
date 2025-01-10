#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") { std::cout << type << " constructor called\n"; }

Dog::Dog(std::string type) : Animal(type) {
  std::cout << type << " constructor called\n";
}

Dog::~Dog(void) { std::cout << type << " deconstructor called\n"; }

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << type << " copy constructor called\n";
  type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << type << " copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void Dog::makeSound(void) const { std::cout << type << " barks...\n"; }
