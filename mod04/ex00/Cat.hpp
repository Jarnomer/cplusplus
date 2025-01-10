#pragma once

#include "Animal.hpp"

#include <iostream>
#include <string>

class Cat : public Animal {
public:
  Cat(void);
  Cat(std::string type);
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat(void);

public:
  void makeSound(void) const;
};
