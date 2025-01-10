#pragma once

#include "Animal.hpp"

#include <iostream>
#include <string>

class Dog : public Animal {
public:
  Dog(void);
  Dog(std::string type);
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog(void);

public:
  void makeSound(void) const;
};
