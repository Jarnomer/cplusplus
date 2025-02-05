#pragma once

#define GREEN  "\033[32m"
#define CYAN   "\033[36m"
#define RED    "\033[31m"
#define RESET  "\033[0m"

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
  static bool debugMode;

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

private: // insert template
  template <typename Container>
  static void insertNumbers(Container &main, Container &pend, Container &left,
                     Container &container, int elementSize, bool hasOddElem, int odd,
                     size_t jc = 3, size_t insertedNumbers = 0, size_t boundaryDecrement = 0,
                     size_t numberChunkSize = 0, size_t searchDistance = 0) {

    if (pend.size() == 1) {

        // If there’s only one element in pend, insert directly into main with binary search.
        auto end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());

    } else {

      // Loop till all the biggest numbers of smaller elements from pend to are moved to main.
      while (!pend.empty()) {

        // Size of the current chunk of numbers to be inserted based on Jacobsthal sequence.
        numberChunkSize = JacobsthalNumber(jc) - JacobsthalNumber(jc - 1);

        // Adjust chunk size if it exceeds the remaining pend.
        if (numberChunkSize > pend.size()) {
          numberChunkSize = pend.size();
        }

        // Decrease the total boundary of search distance based on inserted numbers.
        boundaryDecrement = 0;

        // Inner loop to process the current chunk of numbers.
        while (numberChunkSize > 0) {

          // Search distance based on current Jacobsthal and inserted numbers.
          searchDistance = JacobsthalNumber(jc + insertedNumbers) - boundaryDecrement;

          // Initial end-point is the end of main.
          auto end = main.end();

          // Adjust the end-point if distance is within the size of main.
          if (searchDistance <= main.size()) {
            end = main.begin() + searchDistance;
          }

          // Pend number to be found based on remaining chunk size.
          auto targetElement = pend.begin() + numberChunkSize - 1;

          // Binary search the position of pend number from main.
          end = std::upper_bound(main.begin(), end, *targetElement);

          // Move found number to main and remove it from pend.
          main.insert(end, *targetElement);
          pend.erase(targetElement);

          // Increment the count of inserted numbers.
          insertedNumbers++;

          // Increase boundary decrement to adjust search distance.
          boundaryDecrement++;

          // Reduce the chunk size since element was moved.
          numberChunkSize--;

        }

        // Move to next Jacobsthal number for next chunk.
        jc++;

      }
    }

    Container temp; // Temporary container to hold the final result.

    if (hasOddElem) {
        // Insert largest number of odd element into main.
        // Using binary search, since it does not have a pair.
        auto end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }

    // Populate the temp with elements from main, which holds sorted.
    for (auto it = main.begin(); it != main.end(); ++it) {
        // Find the corresponding largest number from current container.
        // Insert it and previous numbers based on element size to temp.
        auto itf = std::find(container.begin(), container.end(), *it);
        temp.insert(temp.end(), itf - (elementSize - 1), itf + 1);
    }

    // Append all of the leftover numbers from left to the end of temp.
    temp.insert(temp.end(), left.begin(), left.end());

    // Override the original container with temp.
    container = temp;
}

private: // sort template
  template <typename Container> // lvl is only used for debugging
  static void sortNumbers(Container &container, int lvl = -1) {

    // Tracks the current amount of pairs of numbers in element.
    static int elementSize = 1;

    // Calculate the amount of elements in current recursion.
    int elementCount = container.size() / elementSize;

    // Stop recursion if there isn't enough elements to compare.
    if (elementCount < 2) {
      return;
    }

    // Check if the number of elements is odd.
    bool hasOddElem = (elementCount % 2 == 1) ? true : false;

    // Store begin-point.
    auto begin = container.begin();

    // Set end-point to ignore unpaired odd elements.
    auto end = begin + ((elementSize * elementCount) - (hasOddElem * elementSize));

    // Iterate over all pairs of elements in container.
    for (auto it = begin; it != end; it += (elementSize * 2)) {
      // Compare last numbers of elements, swap whole element if second is smaller.
      if (*(it + (elementSize - 1)) > *(it + (elementSize * 2 - 1))) {
        std::swap_ranges(it, it + elementSize, it + elementSize);
      }
    }

    elementSize *= 2;               // Double the size of elements for each recursion.
    sortNumbers(container, ++lvl);  // Recursive call.
    elementSize /= 2;               // Devide the size of elements in recursive call-back.

    Container main;  // Holds already sorted numbers from larger elements.
    Container pend;  // Holds pend numbers from smaller elementes for insertion.
    Container left;  // Holds leftover odd numbers which were not paired.

    // Initialize main with largest numbers from first two elements.
    // There are no elements before them and they are already sorted.
    main.push_back(*(begin + elementSize - 1));
    main.push_back(*(begin + elementSize * 2 - 1));

    // Loop through other largest numbers in remaining elements.
    for (auto it = begin + elementSize * 2; it != end; it += elementSize) {

      // Push the last number of larger element into main.
      main.push_back(*(it + elementSize * 2 - 1));

      // Push the last number of smaller element into pend.
      pend.push_back(*(it + elementSize - 1));

      // Jump to next element pair by advancing the iterator.
      std::advance(it, elementSize);

    }

    // Add all numbers of the odd element into left to combine them into main later.
    left.insert(left.end(), end + (elementSize * hasOddElem), container.end());

    // Debug print all containers before insertion if debugging is enabled.
    debugPrint("Before insert | Recursion level: " + std::to_string(lvl) + 
               " | Element Size: " + std::to_string(elementSize),
               container, main, pend, left, elementSize);
    
    if (hasOddElem || !pend.empty()) {
      // Call binary insertion to merge pend elements and leftovers into main.
      insertNumbers(main, pend, left, container, elementSize, hasOddElem, 
             hasOddElem ? *(end + elementSize - 1) : -1);
    }

    // Debug print all containers after insertion if debugging is enabled.
    debugPrint("After insert | Recursion level: " + std::to_string(lvl) + 
               " | Element Size: " + std::to_string(elementSize),
               container, main, pend, left, elementSize);
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

private: // debug print template
  template <typename Container>
  static void debugPrint(const std::string &title, const Container &vec, const Container &main, 
                         const Container &pend, const Container &left, size_t elementSize) {

    if (!debugMode) {
        return;
    }

    size_t maxSize = std::max({vec.size(), main.size(), pend.size(), left.size()});
    size_t tableWidth = 10 + (5 * maxSize) + (maxSize / elementSize) * 2 + 1;

    std::cout << GREEN << std::string(tableWidth / 2 - title.size() / 2, '=') << " " << title << " " 
              << std::string(tableWidth / 2 - title.size() / 2 - 1, '=') << RESET << "\n";

    std::cout << CYAN << std::setw(10) << "   Index  |" << RESET;
    for (size_t i = 0; i < maxSize; ++i) {
      std::cout << std::setw(5) << i;
      if ((i + 1) % elementSize == 0 && i + 1 < maxSize) {
        std::cout << " |";
      }
    }

    std::cout << "\n" << GREEN << std::string(tableWidth + 1, '-') << RESET << "\n";

    auto printRow = [&](const std::string &label, const Container &container) {
      std::cout << CYAN << std::setw(10) << label << "|" << RESET;
      for (size_t i = 0; i < maxSize; ++i) {
        if (i < container.size()) {
          std::cout << std::setw(5) << container[i];
        } else {
          std::cout << RED << std::setw(5) << "-" << RESET;
        }
        if ((i + 1) % elementSize == 0 && i + 1 < maxSize) {
          std::cout << " |";
        }
      }
      std::cout << "\n";
    };

    printRow("Vec  ", vec);
    printRow("Main  ", main);
    printRow("Pend  ", pend);
    printRow("Left  ", left);

    std::cout << GREEN << std::string(tableWidth, '=') << RESET << "\n";
  }
};
