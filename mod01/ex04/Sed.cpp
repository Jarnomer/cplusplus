#include "Sed.hpp"

void Sed::replace() {
  std::stringstream input;
  std::stringstream result;
  size_t next = 0;
  size_t prev = 0;
  int total_length;

  input << infile.rdbuf();
  if (s1.empty()) {
    outfile << input.str();
    return;
  }
  while (next != std::string::npos && !s1.empty()) {
    next = input.str().find(s1, prev);
    result << input.str().substr(prev, next - prev) << s2;
    prev = next + s1.length();
  }
  total_length = result.str().length() - s2.length();
  outfile << result.str().substr(0, total_length);
}

static std::string outfile_name(std::string file, std::string extension) {
  if (file.find_first_of(".")) {
    return (file.substr(0, file.find_first_of(".")) + extension);
  } else {
    return (file + extension);
  }
}

Sed::Sed(std::string file, std::string s1, std::string s2) : file(file), s1(s1), s2(s2) {
  std::string newFile;

  newFile = outfile_name(file, ".replace");
  infile.open(file, std::fstream::in);
  if (infile.fail()) {
    std::cout << file << ": " << strerror(errno) << std::endl;
    return;
  }
  outfile.open(newFile, std::fstream::out);
  if (outfile.fail()) {
    std::cout << newFile << ": " << strerror(errno) << std::endl;
  }
}

Sed::~Sed(void) {
  if (infile.is_open())
    infile.close();
  if (outfile.is_open())
    outfile.close();
}
