#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << "ScavTrap (" << getName() << ") constructor called" << std::endl;
  damage = 20;
  health = 100;
  energy = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap (" << getName() << ") constructor called" << std::endl;
  damage = 20;
  health = 100;
  energy = 50;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap (" << getName() << ") deconstructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this == &other) {
    return *this;
  } else {
    (ClapTrap::operator=(other));
    return *this;
  }
}

void ScavTrap::attack(const std::string &target) {
  if (getHealth() <= 0) {
    std::cout << "ScavTrap " << getName() << " has no health to act" << std::endl;
    return;
  } else if (getEnergy() <= 0) {
    std::cout << "ScavTrap " << getName() << " has no energy to act" << std::endl;
    return;
  } else {
    setEnergy(getEnergy() - 1);
    std::cout << "ScavTrap " << getName() << " used 1 energy to attack "
              << target << " causing " << getDamage() << " points of damage"
              << ". Remaining energy: " << getEnergy() << std::endl;
  }
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << getName() << " is now in gate keeper mode" << std::endl;
}
