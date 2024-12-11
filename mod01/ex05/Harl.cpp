#include "Harl.hpp"

void Harl::debug(void) { std::cout << "Example debug message" << std::endl; }

void Harl::info(void) { std::cout << "Example info message" << std::endl; }

void Harl::warning(void) { std::cout << "Example warning message" << std::endl; }

void Harl::error(void) { std::cout << "Example error message" << std::endl; }

void Harl::complain(std::string level) {
  void (Harl::*log[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[4] = {"DEBUG", "ERROR", "INFO", "WARNING"};

  std::cout << "[ " << level << " ]" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (level == levels[i]) {
      (this->*log[i])();
      break;
    } else if (i == 3) {
      std::cout << "Invalid logging level" << std::endl;
      break;
    }
  }
}
