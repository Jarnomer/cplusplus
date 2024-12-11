#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

class Sed {
private:
  const std::string file;
  const std::string s1;
  const std::string s2;
  std::ifstream infile;
  std::ofstream outfile;

public:
  Sed(std::string file, std::string s1, std::string s2);
  ~Sed(void);
  void replace(void);
};
