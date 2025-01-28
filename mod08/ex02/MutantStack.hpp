#pragma once

#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {

public: // add support to ::iterator assignment
  typedef typename std::deque<T>::iterator iterator;

public: // constructor
  MutantStack() : std::stack<T>() {
    std::cout << "Default constructor called\n";
  }

public: // copy constructor
  MutantStack(MutantStack const &other) : std::stack<T>(other) {
    std::cout << "Copy constructor called\n";
  }

public: // copy assignment
  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
      std::cout << "Copy assignment called\n";
      std::stack<T>::operator=(other);
    }
    return *this;
  }

public: // deconstructor
  ~MutantStack() { std::cout << "Deconstructor called\n"; }

public: // iterators
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};
