#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <deque>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class PmergeMe {

private: // typedefs
  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::time_point<Clock> time_point_t;
  typedef std::chrono::microseconds us;

private: // attributes
  static std::vector<int> intVector;
  static std::deque<int> intDeque;
  static std::unordered_set<int> uniques;

public: // constructors
  PmergeMe(void) = delete;
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;
  ~PmergeMe(void) = delete;

public: // algorithm
  static void fordJohnsonSort(int argc, char **argv);

private: // parser
  static void parseArguments(int argc, char **argv);

private: // sort template
  template <typename Container> 
  static void sortNumbers(Container &container, size_t unitSize = 1) {
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
    sortNumbers(container, unitSize * 2);
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

private: // duration print template
  template <typename Container> 
  static void printDuration(const std::string &containerType, Container &container, 
                            time_point_t startTime, time_point_t endTime) {
    auto duration = std::chrono::duration_cast<us>(endTime - startTime);
    std::cout << "Time to process a range of " << container.size()
              << " numbers with " << containerType << " : "
              << duration.count() << " μs" << std::endl;
  }

public: // numbers print template
  template <typename Container>
  static void printNumbers(const std::string &tag, const Container &container) {
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