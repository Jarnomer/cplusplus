#pragma once

#include <iostream>
#include <string>

class Animal {
public:
  Animal(void);
  Animal(std::string type);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);

  virtual ~Animal(void);

public:
  void setType(std::string type);
  std::string getType(void) const;

public:
  virtual void makeSound(void) const = 0;

protected:
  std::string type;
};
