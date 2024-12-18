#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
  {
    Weapon club1 = Weapon("crude spiked club");
    HumanA bob("Bob", club1);

    bob.attack();
    club1.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club1 = Weapon("crude spiked club");
    HumanB jim("Jim");

    jim.attack();
    jim.setWeapon(club1);
    jim.attack();
    club1.setType("some other type of club");
    jim.attack();
  }
  return 0;
}
