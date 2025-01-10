#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap (" << name << ") constructor called" << std::endl;
  setDamage(FragTrap::getDamage());
  setHealth(FragTrap::getHealth());
  setEnergy(ScavTrap::getEnergy());
  this->name = "Default";
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  std::cout << "DiamondTrap (" << name << ") constructor called" << std::endl;
  setDamage(FragTrap::getDamage());
  setHealth(FragTrap::getHealth());
  setEnergy(ScavTrap::getEnergy());
  this->name = name;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap (" << name << ") deconstructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  if (this == &other) {
    return *this;
  } else {
    ClapTrap::operator=(other);
    name = other.name;
    return *this;
  }
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap " << name << "'s ClapTrap name is: " 
            << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}
