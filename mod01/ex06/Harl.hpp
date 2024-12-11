#pragma once

#include <iostream>
#include <string>

class Harl {
private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void set_log_level(std::string level);

  int logLevel;

public:
  Harl(void);
  ~Harl(void);
  void filter(std::string level);
};
