#include <iostream>

#define ADDR(ptr) std::cout << "Address: " << ptr << std::endl;
#define LOG(str) std::cout << "Value: " << str << std::endl;

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  ADDR(&str);
  ADDR(stringPTR);
  ADDR(&stringREF);

  LOG(str);
  LOG(*stringPTR);
  LOG(stringREF);

  return 0;
}
