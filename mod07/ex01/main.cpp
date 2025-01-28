#include "iter.hpp"

#include <iostream>

int main(void) {
  size_t length, multiplier = 10;

  int arr[] = {1, 2, 3, 4, 5};
  std::string names[] = {"Alice", "Bob", "Charlie"};

  auto print = [](const auto &x) { std::cout << x << " "; };
  auto multiply = [&](auto &x) { x *= multiplier; };
  auto surname = [](std::string &name) { name += " Smith"; };

  length = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Original array: ";
  iter(arr, length, print);
  std::cout << std::endl;
  std::cout << "Array after multipling elements: ";
  iter(arr, length, multiply);
  iter(arr, length, print);
  std::cout << std::endl;

  length = sizeof(names) / sizeof(names[0]);
  std::cout << "Original names: ";
  iter(names, length, print);
  std::cout << std::endl;
  std::cout << "Names after adding surnames: ";
  iter(names, length, surname);
  iter(names, length, print);
  std::cout << std::endl;

  return 0;
}
