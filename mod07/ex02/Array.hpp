#pragma once

#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *array;
  unsigned int n; // size

public: // default constructor
  Array(void) : array(nullptr), n(0) {
    std::cout << "Default constructor called\n";
  }

public: // parametric constructor
  Array(unsigned int n) : array(new T[n]), n(n) {
    std::cout << "Parametric constructor called\n";
  }

public: // copy constructor
  Array(const Array &other) : array(new T[other.n]), n(other.n) {
    std::cout << "Copy constructor called\n";
    for (unsigned int i = 0; i < other.n; i++) {
      this->array[i] = other.array[i];
    }
  }

public: // copy assignment
  Array &operator=(const Array &other) {
    std::cout << "Copy assignment called\n";
    if (this != &other) {
      this->n = other.n;
      delete[] this->array;
      this->array = new T[n];
      for (unsigned int i = 0; i < n; i++) {
        this->array[i] = other.array[i];
      }
    }
    return *this;
  }

public: // subscript operator for non-const objects
  T &operator[](unsigned int index) {
    if (index >= n) {
      throw std::out_of_range("Index out of bounds");
    } else {
      return array[index];
    }
  }

public: // subscript operator for const objects
  const T &operator[](unsigned int index) const {
    if (index >= n) {
      throw std::out_of_range("Index out of bounds");
    } else {
      return array[index];
    }
  }

public: // deconstructor
  ~Array(void) { delete[] array; }

public: // getters
  unsigned int size() const { return n; }
};
