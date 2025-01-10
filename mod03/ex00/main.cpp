#include "ClapTrap.hpp"

int main(void) {
  std::cout << "\nTesting Methods\n\n";
  ClapTrap claptrap("Trappy");
  claptrap.attack("Unknown");
  claptrap.takeDamage(5);
  claptrap.beRepaired(5);
  claptrap.takeDamage(20);
  claptrap.attack("Unknown");
  claptrap.setHealth(1);
  claptrap.setEnergy(0);
  claptrap.attack("Unknown");

  std::cout << "\nTesting copy constructor\n\n";
  {
    claptrap.setHealth(9001);
    ClapTrap duplicate(claptrap);
    std::cout << "\n";
    std::cout << claptrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }

  std::cout << "\nTesting copy assigment\n\n";
  {
    ClapTrap duplicate("Trappier");
    claptrap.setHealth(42);
    duplicate = claptrap;
    std::cout << "\n";
    std::cout << claptrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }

  std::cout << "\nDeconstructors...\n\n";
  return 0;
}
