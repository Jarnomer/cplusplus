#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
private:
  std::string name;
  Weapon *weapon;

public:
  HumanB(std::string name);
  void attack(void);
  void setWeapon(Weapon &weapon);
};
