#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : name("Default"), damage(0), health(10), energy(10) {
  std::cout << "ClapTrap (" << name << ") constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), damage(0), health(10), energy(10) {
  std::cout << "ClapTrap (" << name << ") constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap (" << name << ") deconstructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  name = other.name;
  damage = other.damage;
  health = other.health;
  energy = other.energy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  if (this == &other) {
    return *this;
  } else {
    name = other.name;
    damage = other.damage;
    health = other.health;
    energy = other.energy;
    return *this;
  }
}

void ClapTrap::attack(const std::string &target) {
  if (health <= 0) {
    std::cout << "ClapTrap " << name << " has no health to act" << std::endl;
    return;
  } else if (energy <= 0) {
    std::cout << "ClapTrap " << name << " has no energy to act" << std::endl;
    return;
  } else {
    energy -= 1;
    std::cout << "ClapTrap " << name << " used 1 energy to attack " << target
              << " causing " << damage << " points of damage"
              << ". Remaining energy: " << energy << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  health -= amount;
  std::cout << "ClapTrap " << name << " takes " << amount << " of damage"
            << ". Remaining health: " << health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energy <= 0) {
    std::cout << "ClapTrap " << name << " has no energy to act" << std::endl;
    return;
  } else {
    energy -= 1;
    health += amount;
    std::cout << "ClapTrap " << name << " used 1 energy to repair " << amount
              << " of health" << ". Current health: " << health
              << ". Remaining energy: " << energy << std::endl;
  }
}

void ClapTrap::setName(std::string name) { this->name = name; }
void ClapTrap::setDamage(unsigned int amount) { this->damage = amount; }
void ClapTrap::setHealth(unsigned int amount) { this->health = amount; }
void ClapTrap::setEnergy(unsigned int amount) { this->energy = amount; }

std::string ClapTrap::getName(void) { return name; }
int ClapTrap::getDamage(void) { return damage; }
int ClapTrap::getHealth(void) { return health; }
int ClapTrap::getEnergy(void) { return energy; }
