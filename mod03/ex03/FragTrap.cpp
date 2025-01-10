#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "FragTrap (" << getName() << ") constructor called" << std::endl;
  damage = 30;
  health = 100;
  energy = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap (" << getName() << ") constructor called" << std::endl;
  damage = 30;
  health = 100;
  energy = 100;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap (" << getName() << ") deconstructor called"
            << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  if (this == &other) {
    return *this;
  } else {
    (ClapTrap::operator=(other));
    return *this;
  }
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << getName() << " demands high five!" << std::endl;
}
