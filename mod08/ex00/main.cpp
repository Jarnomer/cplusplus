#include "easyfind.hpp"

#include <array>
#include <iostream>
#include <vector>

int main(void) {
  try {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::array<int, 5> arr = {10, 20, 30, 40, 50};

    auto it1 = easyfind(vec, 3);
    std::cout << "Found in vector: " << *it1 << std::endl;

    auto it2 = easyfind(arr, 50);
    std::cout << "Found in array: " << *it2 << std::endl;

    auto it3 = easyfind(vec, 42);
    std::cout << "Found in array: " << *it3 << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
