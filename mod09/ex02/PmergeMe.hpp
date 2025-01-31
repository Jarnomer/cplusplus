#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class PmergeMe {
private:
  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::time_point<Clock> timePoint;
  typedef std::chrono::microseconds us;

private:
  static std::vector<int> intVector;
  static std::list<int> intList;
  static std::string containerType;
  static timePoint timer;
  static size_t unitSize;

public: // constructors
  PmergeMe(void) = delete;
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;
  ~PmergeMe(void) = delete;

public: // getters
  static std::vector<int> getIntVector(void);
  static std::list<int> getIntList(void);

private: // utilities
  static void startTimer(void);
  static void printDuration(void);

public: // algorithm template
  template <typename T>
  static void fordJohnsonSort(int argc, char **argv, T container) {
    startTimer();
    parseArguments(argc, argv, container);
    displayNumbers("Before", container);
    sortNumbers(container);
    displayNumbers("After", container);
    printDuration(container);
  }

private: // parse template
  template <typename T>
  static void parseArguments(int argc, char **argv, T &container) {
    std::vector<std::string> args(argv + 1, argv + argc);
    std::unordered_set<int> uniques;
    for (const auto &str : args) {
      int number = std::stoi(str);
      if (number < 0) {
        throw std::invalid_argument("Negative number");
      } else if (!uniques.insert(number).second) {
        throw std::invalid_argument("Duplicate number");
      } else {
        container.push_back(number);
      }
    }
    if (container.size() <= 1) {
      throw std::invalid_argument("Not enough numbers");
    }
  }

private: // sort template
  template <typename Container> static void sortNumbers(Container &container) {
    int unitCount = container.size() / unitSize;
    if (unitCount < 2) {
      return;
    }
    bool hasOddElem = (unitCount % 2 == 1) ? true : false;
    auto end = container.begin() + ((unitSize * unitCount) - (hasOddElem * unitSize));
    for (auto it = container.begin(); it != end; it += (unitSize * 2)) {
      if (*(it + (unitSize - 1)) > *(it + ((unitSize * 2) - 1))) {
        std::swap_ranges(it, it + unitSize, it + unitSize);
      }
    }
    unitSize *= 2;
    sortNumbers(container);
    unitSize /= 2;

    // Container mainChain;
    // Container pendChain;
    // Container leftOvers;

    // // Generate 'main' and 'pend' containers based on the current unitSize.
    // mainChain.push_back(*(container.begin() + unitSize - 1)); // Push the element from the end of the first pair (a1).
    // mainChain.push_back(*(container.begin() + unitSize * 2 - 1)); // Push the element from the end of the second pair (b1).

    // for (auto it = container.begin() + unitSize * 2; it != end; it += unitSize) {
    //   pendChain.push_back(*(it + unitSize - 1)); // Push elements from 'pend' to 'main'.
    //   it += unitSize;
    //   mainChain.push_back(*(it + unitSize - 1)); // Push elements from 'main' to 'pend'.
    // }

    // if (hasOddElem)
    //   auto odd = *(end + order - 1); // Save the odd pair if any

    // leftOvers.insert(leftOvers.end(), end + (order * hasOddElem), vec.end()); // Save the leftover elements that cannot form pairs on their own.

  }

private: // duration template
  template <typename T> static void printDuration(const T &container) {
    auto endTime = Clock::now();
    auto duration = std::chrono::duration_cast<us>(endTime - timer);
    std::cout << "Time to process a range of " << container.size()
              << " units with " << containerType << " : " << duration.count()
              << " μs" << std::endl;
  }

public: // print template
  template <typename T>
  static void displayNumbers(const std::string &tag, const T &container) {
    std::cout << tag << " : ";
    for (const auto &num : container) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
};

// Template function to overload the << operator for any container
// template<typename Container>
// std::ostream& operator<<(std::ostream& os, const Container& container) {
//   for (auto it = container.begin(); it != container.end(); ++it) {
//     os << *it << " ";
//   }
//   return os;
// }