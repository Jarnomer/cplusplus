#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
  std::cout << type << " constructor called\n";
}

Animal::Animal(std::string type) : type(type) {
  std::cout << "Animal [" << type << "] constructor called\n";
}

Animal::~Animal(void) {
  std::cout << "Animal [" << type << "] deconstructor called\n";
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal [" << type << "] copy constructor called\n";
  type = other.type;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal [" << type << "] copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void Animal::setType(std::string type) { this->type = type; }

std::string Animal::getType(void) const { return this->type; }

void Animal::makeSound(void) const { std::cout << "Animal sounds...\n"; }
