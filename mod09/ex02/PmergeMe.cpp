#include "PmergeMe.hpp"

std::vector<int> PmergeMe::intVector;
std::list<int> PmergeMe::intList;
std::string PmergeMe::containerType;
size_t PmergeMe::unitSize;

std::chrono::time_point<std::chrono::high_resolution_clock> PmergeMe::timer;

std::vector<int> PmergeMe::getIntVector(void) {
  containerType = "std::vector";
  unitSize = 1;
  return intVector;
}

std::list<int> PmergeMe::getIntList(void) {
  containerType = "std::list";
  unitSize = 1;
  return intList;
}

void PmergeMe::startTimer() { timer = Clock::now(); }
