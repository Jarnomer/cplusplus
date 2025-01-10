#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << type << " constructor called\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
  std::cout << type << " constructor called\n";
}

WrongCat::~WrongCat(void) { std::cout << type << " deconstructor called\n"; }

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << type << " copy constructor called\n";
  type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << type << " copy assignment operator called\n";
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void WrongCat::makeSound(void) const { std::cout << type << " meows...\n"; }
