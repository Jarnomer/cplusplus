#include "Zombie.hpp"

int main(void) {
  static const int count = 5;

  Zombie *horde = zombieHorde(count, "Zombie");
  for (int i = 0; i < count; i++) {
    horde[i].announce();
  }
  delete[] horde;
  return 0;
}
