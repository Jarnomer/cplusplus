#include "FragTrap.hpp"

int main(void) {
  std::cout << "\nTesting Methods\n\n";
  FragTrap fragtrap("Fraggy");
  std::cout << "\n";
  fragtrap.highFivesGuys();

  std::cout << "\nTesting copy constructor\n\n";
  {
    fragtrap.setHealth(9001);
    FragTrap duplicate(fragtrap); 
    std::cout << "\n";
    std::cout << fragtrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }
  std::cout << "\nTesting copy assigment\n\n";
  {
    FragTrap duplicate("Fraggier");
    fragtrap.setHealth(42);
    duplicate = fragtrap;
    std::cout << "\n";
    std::cout << fragtrap.getHealth() << "\n";
    std::cout << duplicate.getHealth() << "\n";
    std::cout << "\n";
  }
  std::cout << "\nDeconstructors...\n\n";
  return 0;
}
