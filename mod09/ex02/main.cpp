#include "PmergeMe.hpp"

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "usage: ./PmergeMe <numbers>";
    return 1;
  } else {
    try {
      PmergeMe::fordJohnsonSort(argc, argv);
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
  return 0;
}
