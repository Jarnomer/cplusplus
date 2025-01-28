#include "Array.hpp"

#include <iostream>

struct Player {
  double score;
  std::string name;
};

std::ostream &operator<<(std::ostream &os, const Player &player) {
  os << "Player name: " << player.name << ", score: " << player.score << "\n";
  return os;
}

int main(void) {
  try {
    Array<Player> players(3);

    players[0] = {95.5, "Alice"};
    players[1] = {89.0, "Bob"};
    players[2] = {76.3, "Charlie"};

    std::cout << "\n";
    std::cout << "Original players\n";
    for (unsigned int i = 0; i < players.size(); ++i) {
      std::cout << players[i];
    }

    std::cout << "\n";
    Array<Player> copiedPlayer(players);
    std::cout << "\nCopied players\n";
    for (unsigned int i = 0; i < copiedPlayer.size(); ++i) {
      std::cout << copiedPlayer[i];
    }

    std::cout << "\n";
    Array<Player> assignedPlayers = players;
    std::cout << "\nAssigned players\n";
    for (unsigned int i = 0; i < assignedPlayers.size(); ++i) {
      std::cout << assignedPlayers[i];
    }

    std::cout << "\nAccessing out of range index\n";
    std::cout << players[3];

  } catch (std::out_of_range &e) {
    std::cout << "Out of range: " << e.what() << "\n";
  } catch (...) {
    std::cout << "Unhandled exception occured!\n";
  }
  return 0;
}
