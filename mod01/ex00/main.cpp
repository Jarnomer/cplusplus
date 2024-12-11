#include "Zombie.hpp"

int main(void) {
  randomChump("randomChump1");
  Zombie *z = newZombie("newZombie1");
  z->announce();
  delete z;
  return 0;
}
