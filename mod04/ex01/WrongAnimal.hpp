#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);

  virtual ~WrongAnimal(void);

public:
  void setType(std::string type);
  std::string getType(void) const;

public:
  void makeSound(void) const;

protected:
  std::string type;
};
