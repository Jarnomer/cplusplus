#include "Harl.hpp"

void Harl::debug(void) { std::cout << "Example debug message" << std::endl; }

void Harl::info(void) { std::cout << "Example info message" << std::endl; }

void Harl::warning(void) { std::cout << "Example warning message" << std::endl; }

void Harl::error(void) { std::cout << "Example error message" << std::endl; }

Harl::Harl(void) : logLevel(4) {}

Harl::~Harl(void) {}

void Harl::set_log_level(std::string level) {
  std::string levels[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (level == levels[i]) {
      logLevel = i;
      return;
    }
  }
}

void Harl::filter(std::string level) {
  void (Harl::*log[4])(void) = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};
  std::string levels[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};

  set_log_level(level);
  if (logLevel > 3) {
    std::cout << "Invalid logging level" << std::endl;
    return;
  }
  for (int i = logLevel; i < 4; i++) {
    std::cout << "[ " << levels[i] << " ]" << std::endl;
    (this->*log[i])();
  }
}
