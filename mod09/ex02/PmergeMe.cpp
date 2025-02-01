#include "PmergeMe.hpp"

std::vector<int> PmergeMe::intVector;
std::deque<int> PmergeMe::intDeque;
std::unordered_set<int> PmergeMe::uniques;

void PmergeMe::fordJohnsonSort(int argc, char **argv) {
    time_point_t vecStart, vecEnd, listStart, listEnd;
    parseArguments(argc, argv);
    printNumbers("Before", intVector);
    vecStart = Clock::now();
    sortNumbers(intVector);
    vecEnd = Clock::now();
    listStart = Clock::now();
    sortNumbers(intDeque);
    listEnd = Clock::now();
    printNumbers("After", intVector);
    printDuration("std::vector", intVector, vecStart, vecEnd);
    printDuration("std::deque", intDeque, vecStart, vecEnd);
  }

void PmergeMe::parseArguments(int argc, char **argv) {
    std::vector<std::string> args(argv + 1, argv + argc);
    std::unordered_set<int> uniques;
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
