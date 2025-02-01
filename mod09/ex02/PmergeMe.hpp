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
                       int elementSize, bool hasOddElem, int odd) {

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
        temp.insert(temp.end(), itf - (elementSize - 1), itf + 1);
    }

    // Append the leftover elements to temp.
    temp.insert(temp.end(), left.begin(), left.end());

    // Override the original container with the new temp container.
    container = temp;
}

private: // insert template
  template <typename Container>
  static void insert(Container &main, Container &pend, Container &left,
                     Container &container, int elementSize, bool hasOddElem, int odd,
                     size_t jc = 3, size_t insertCount = 0, size_t insertRangeSize = 0) {

    if (pend.size() == 1) {

        // If there’s only one element in pend, insert directly into main with binary search.
        auto end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());

    } else {

      // Loop till all elements from pend to are moved to main.
      while (!pend.empty()) {

        // Size of the current chunk based on Jacobsthal sequence.
        insertRangeSize = JacobsthalNumber(jc) - JacobsthalNumber(jc - 1);

        // Adjust chunk size if it exceeds the remaining pend.
        if (insertRangeSize > pend.size()) {
          insertRangeSize = pend.size();
        }

        // Inner loop to process the current chunk.
        size_t searchRangeShift = 0;
        while (insertRangeSize) {

          // Initial end-point.
          auto end = main.end();

          // Adjust end-point offset based on Jacobsthal number.
          size_t searchRangeOffset = JacobsthalNumber(jc + insertCount) - searchRangeShift;
          if (searchRangeOffset <= main.size()) {
            end = main.begin() + searchRangeOffset;
          }

          // Set pend element base on current Jacobsthal number.
          auto pendElement = pend.begin() + insertRangeSize - 1;

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
          insertRangeSize--;

        }

        // After processing the current chunk, move to the next Jacobsthal number.
        jc++;

      }
    }

    // Override the original container with elements from main and leftover.
    override(container, main, left, elementSize, hasOddElem, odd);
}

private: // sort template
  template <typename Container>
  static void sortNumbers(Container &container) {

    static int elementSize = 1;

    int elementCount = container.size() / elementSize;

    if (elementCount < 2) {
      return;
    }

    bool hasOddElem = (elementCount % 2 == 1) ? true : false;

    auto begin = container.begin();
    auto end = begin + ((elementSize * elementCount) - (hasOddElem * elementSize));

    for (auto it = begin; it != end; it += (elementSize * 2)) {
      if (*(it + (elementSize - 1)) > *(it + (elementSize * 2 - 1))) {
        std::swap_ranges(it, it + elementSize, it + elementSize);
      }
    }

    elementSize *= 2;
    sortNumbers(container);
    elementSize /= 2;

    Container main;
    Container pend;
    Container left;

    main.push_back(*(begin + elementSize - 1));
    main.push_back(*(begin + elementSize * 2 - 1));

    for (auto it = begin + elementSize * 2; it < end; it += elementSize) {
      pend.push_back(*(it + elementSize - 1));
      main.push_back(*(it + elementSize * 2 - 1));
      std::advance(it, elementSize);
    }

    left.insert(left.end(), end + (elementSize * hasOddElem), container.end());

    if (hasOddElem || !pend.empty()) {
      insert(main, pend, left, container, elementSize, hasOddElem, 
             hasOddElem ? *(end + elementSize - 1) : -1);
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