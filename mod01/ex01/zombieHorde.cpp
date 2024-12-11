#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *h = new Zombie[N];
  for (int i = 0; i < N; i++) {
    h[i].set_name(name);
  }
  return h;
}
