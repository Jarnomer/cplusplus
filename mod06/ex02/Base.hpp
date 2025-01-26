#pragma once

#include <iostream>
#include <random>

class Base {
public:
  virtual ~Base(void);
  static Base *generate(void);
  static void identify(Base *p);
  static void identify(Base &p);
};
