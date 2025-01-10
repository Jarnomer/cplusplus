#pragma once

#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
public:
  WrongCat(void);
  WrongCat(std::string type);
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);
  ~WrongCat(void);

public:
  void makeSound(void) const;
};
