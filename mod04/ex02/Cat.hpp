#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

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
  void setIdea(unsigned int index, std::string idea);
  std::string getIdea(unsigned int index) const;

public:
  void makeSound(void) const;

private:
  Brain *brain;
};
