#pragma once

#include <algorithm>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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
  static const bool debugMode;

public: // constructors
  PmergeMe(void) = delete;
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;
  ~PmergeMe(void) = delete;

public: // public method
  static void fordJohnsonSort(int argc, char **argv);

private: // private utils
  static void parseArguments(int argc, char **argv);
  static int JacobsthalNumber(int k);

private:  // override template
  template <typename Container>
  static void override(Container &container, Container &main, Container &left,
                       int unitSize, bool hasOddElem, int odd) {

    Container temp; // Temporary container to hold the final result.

    if (hasOddElem) {
        // Insert odd elements into main using binary search.
        auto end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }

    // Populate the temp container with chunks from the main.
    for (auto it = main.begin(); it != main.end(); ++it) {
        // Find the corresponding element from container and insert the chunk into temp.
        auto itf = std::find(container.begin(), container.end(), *it);
        temp.insert(temp.end(), itf - (unitSize - 1), itf + 1);
    }

    // Append the leftover elements to temp.
    temp.insert(temp.end(), left.begin(), left.end());

    // Override the original container with the new temp container.
    container = temp;
}

private: // insert template
  template <typename Container>
  static void insert(Container &main, Container &pend, Container &left,
                   Container &container, int unitSize, bool hasOddElem, int odd,
                   size_t jc = 3, size_t insertCount = 0, size_t chunkSize = 0) {

    if (pend.size() == 1) {

        // If there’s only one element in pend, insert directly into main with binary search.
        auto end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());

    } else {

      // Loop till all elements from pend to are moved to main.
      while (!pend.empty()) {

        // Size of the current chunk based on Jacobsthal sequence.
        chunkSize = JacobsthalNumber(jc) - JacobsthalNumber(jc - 1);

        // Adjust if the chunk size exceeds the remaining pend.
        if (chunkSize > pend.size()) {
          chunkSize = pend.size();
        }

        // Inner loop to process the current chunk.
        size_t searchRangeShift = 0;
        while (chunkSize) {

          // Initial end-point.
          auto end = main.end();

          // Adjust end-point offset based on Jacobsthal number.
          size_t searchRangeOffset = JacobsthalNumber(jc + insertCount) - searchRangeShift;
          if (searchRangeOffset <= main.size()) {
            end = main.begin() + searchRangeOffset;
          }

          // Set pend element base on current Jacobsthal number.
          auto pendElement = pend.begin() + chunkSize - 1;

          // Binary search the position of pend element from main.
          end = std::upper_bound(main.begin(), end, *pendElement);

          // Move found element to main remove it from pend.
          main.insert(end, *pendElement);
          pend.erase(pendElement);

          // Adjust the shift of search range by one element.
          searchRangeShift++;

          // Increment the count of inserted elements by one.
          insertCount++;

          // Reduce the size of chunk since element was moved.
          chunkSize--;

        }

        // After processing the current chunk, move to the next Jacobsthal number.
        jc++;

      }
    }

    // Override the original container with elements from main and leftover.
    override(container, main, left, unitSize, hasOddElem, odd);
}

private: // sort template
  template <typename Container>
  static void sortNumbers(Container &container, size_t recursionLevel = 1) {

    static int unitSize = 1;

    int unitCount = container.size() / unitSize;

    if (unitCount < 2) {
      return;
    }

    bool hasOddElem = (unitCount % 2 == 1) ? true : false;

    auto begin = container.begin();
    auto end = begin + ((unitSize * unitCount) - (hasOddElem * unitSize));

    for (auto it = begin; it != end; it += (unitSize * 2)) {
      if (*(it + (unitSize - 1)) > *(it + (unitSize * 2 - 1))) {
        std::swap_ranges(it, it + unitSize, it + unitSize);
      }
    }

    unitSize *= 2;
    sortNumbers(container, ++recursionLevel);
    unitSize /= 2;

    Container main;
    Container pend;
    Container left;

    main.push_back(*(begin + unitSize - 1));
    main.push_back(*(begin + unitSize * 2 - 1));

    for (auto it = begin + unitSize * 2; it < end; it += unitSize) {
      pend.push_back(*(it + unitSize - 1));
      main.push_back(*(it + unitSize * 2 - 1));
      std::advance(it, unitSize);
    }

    left.insert(left.end(), end + (unitSize * hasOddElem), container.end());

    if (hasOddElem || !pend.empty()) {
      insert(main, pend, left, container, unitSize, hasOddElem, 
             hasOddElem ? *(end + unitSize - 1) : -1);
    }
  }

private: // duration print template
  template <typename Container>
  static void printDuration(const std::string &containerType, Container &container,
                            time_point_t startTime, time_point_t endTime) {
    auto duration = std::chrono::duration_cast<us>(endTime - startTime);
    std::cout << "Time to process a range of " << container.size() << " numbers with "
              << containerType << " : " << std::fixed << std::setprecision(5) 
              << duration.count() << " μs" << std::endl;
  }

private: // numbers print template
  template <typename Container>
  static void printNumbers(const std::string &tag, const Container &container) {
    std::cout << tag << " : ";
    for (const auto &num : container) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
};

// if (debugMode) {
//   std::cout << "\nrecursion: " << recursionLevel;
//   std::cout << "\n==================\n";
//   printNumbers("main", main);
//   printNumbers("pend", pend);
//   printNumbers("left", left);
//   std::cout << "==================\n";
// }