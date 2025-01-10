#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
  std::cout << type << " constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
  std::cout << "WrongAnimal [" << type << "] constructor called\n";
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal [" << type << "] deconstructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal [" << type << "] copy constructor called\n";
  type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal [" << type << "] copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void WrongAnimal::setType(std::string type) { this->type = type; }

std::string WrongAnimal::getType(void) const { return this->type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "Wrong animal sounds...\n";
}
