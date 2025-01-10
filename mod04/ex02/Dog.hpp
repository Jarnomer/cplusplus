#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

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
  void setIdea(unsigned int index, std::string idea);
  std::string getIdea(unsigned int index) const;

public:
  void makeSound(void) const;

private:
  Brain *brain;
};
