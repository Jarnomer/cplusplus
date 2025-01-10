#include "DiamondTrap.hpp"

int main(void) {
  std::cout << "\nTesting Methods\n\n";
  DiamondTrap diamondtrap("Shiny");
  std::cout << "\n";
  diamondtrap.whoAmI();

  std::cout << "\nTesting copy constructor\n\n";
  {
    diamondtrap.setHealth(9001);
    DiamondTrap duplicate(diamondtrap); 
    std::cout << "\n";
    std::cout << diamondtrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }

  std::cout << "\nTesting copy assigment\n\n";
  {
    DiamondTrap duplicate("Shinier");
    std::cout << "\n";
    diamondtrap.setHealth(42);
    duplicate = diamondtrap;
    std::cout << "\n";
    std::cout << diamondtrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }

  std::cout << "\nDeconstructors...\n\n";
  return 0;
}
