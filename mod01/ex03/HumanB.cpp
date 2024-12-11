#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

void HumanB::attack(void) {
  if (weapon) {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
  } else {
    std::cout << name << " attacks with their kung-fu" << std::endl;
  }
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
