#include "ScavTrap.hpp"

int main(void) {
  std::cout << "\nTesting Methods\n\n";
  ScavTrap scavtrap("Scavvy");
  std::cout << "\n";
  scavtrap.attack("Unknown");
  std::cout << "\n";
  scavtrap.guardGate();

  std::cout << "\nTesting copy constructor\n\n";
  { 
    scavtrap.setHealth(9001);
    ScavTrap duplicate(scavtrap); 
    std::cout << "\n";
    std::cout << scavtrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }

  std::cout << "\nTesting copy assigment\n\n";
  {
    ScavTrap duplicate("Scavier");
    scavtrap.setHealth(42);
    duplicate = scavtrap;
    std::cout << "\n";
    std::cout << scavtrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }

  std::cout << "\nDeconstructors...\n\n";
  return 0;
}
