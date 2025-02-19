#include "MutantStack.hpp"

#include <list>

int main(void) {
  {
    std::cout << "constructors...\n";
    MutantStack<int> mstack1;
    mstack1.push(42);
    MutantStack<int> mstack2(mstack1);
    MutantStack<int> mstack3;
    mstack3 = mstack2;
    std::cout << "mstack1 element: " << mstack1.top() << "\n";
    std::cout << "mstack2 element: " << mstack2.top() << "\n";
    std::cout << "mstack3 element: " << mstack3.top() << "\n";
  }
  {
    std::cout << std::endl;
    std::cout << "mutantstack...\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }
  {
    std::cout << std::endl;
    std::cout << "std::list...\n";
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
  }
  return 0;
}
