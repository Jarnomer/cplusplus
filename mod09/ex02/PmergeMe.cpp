#include "PmergeMe.hpp"

std::vector<int> PmergeMe::intVector;
std::deque<int> PmergeMe::intDeque;
std::unordered_set<int> PmergeMe::uniques;

void PmergeMe::fordJohnsonSort(int argc, char **argv) {
  time_point_t vecStart, vecEnd, deqStart, deqEnd;
  parseArguments(argc, argv);
  printNumbers("Before", intVector);
  vecStart = Clock::now();
  sortNumbers(intVector);
  vecEnd = Clock::now();
  deqStart = Clock::now();
  sortNumbers(intDeque);
  deqEnd = Clock::now();
  printNumbers("After", intVector);
  printDuration("std::vector", intVector, vecStart, vecEnd);
  printDuration("std::deque", intDeque, deqStart, deqEnd);
}

void PmergeMe::parseArguments(int argc, char **argv) {
  std::vector<std::string> args(argv + 1, argv + argc);
  for (const auto &str : args) {
    int number = std::stoi(str);
    if (number < 0) {
      throw std::invalid_argument("Negative number");
    } else if (!uniques.insert(number).second) {
      throw std::invalid_argument("Duplicate number");
    } else {
      intVector.push_back(number);
      intDeque.push_back(number);
    }
  }
  if (uniques.size() <= 1) {
    throw std::invalid_argument("Not enough numbers");
  }
}

int PmergeMe::JacobsthalNumber(int k) {
  return round((pow(2, k + 1) + pow(-1, k)) / 3);
}
