#include "Intern.hpp"

Intern::Intern(void) { std::cout << "Intern default constructor called\n"; }

Intern::~Intern(void) { std::cout << "Intern deconstructor called\n"; }

const char *Intern::FormNotFoundException::what() const noexcept {
  return "Invalid form name!";
}

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string valid[] = {"shrubbery", "robotomy", "president"};
  int i = 0;
  for (const auto &it : valid) {
    if (it == name) {
      break;
    } else {
      i++;
    }
  }
  switch (i) {
  case 0:
    return new ShrubberyCreationForm(target);
  case 1:
    return new RobotomyRequestForm(target);
  case 2:
    return new PresidentialPardonForm(target);
  default:
    throw Intern::FormNotFoundException();
  }
}
