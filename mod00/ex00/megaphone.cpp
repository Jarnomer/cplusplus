#include <iostream>

std::string ft_to_upper(std::string str) {
  for (int i = 0; i < (int)str.length(); i++) {
    str[i] = toupper(str[i]);
  }
  return (str);
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; i++) {
      std::cout << ft_to_upper(argv[i]);
    }
  }
  std::cout << std::endl;
  return 0;
}
