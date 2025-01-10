#pragma once

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {
public:
  ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);
  ~ScavTrap(void);

public:
  void attack(const std::string &target);
  void guardGate(void);
};
