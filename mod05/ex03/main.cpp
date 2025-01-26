#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
  std::string valid[] = {"shrubbery", "robotomy", "president"};
  Intern i;
  AForm *p;

  try {
    p = i.makeForm("A", "Jackson");
    delete p;
  } catch (std::exception &e) {
    std::cout << "exception caught: " << e.what() << "\n";
  }

  std::cout << "\n";

  try {
    p = i.makeForm(valid[2], "Trump");
    delete p;
  } catch (std::exception &e) {
    std::cout << "exception caught: " << e.what() << "\n";
  }

  std::cout << "\n";

  try {
    p = i.makeForm(valid[1], "Robocop");
    delete p;
  } catch (std::exception &e) {
    std::cout << "exception caught: " << e.what() << "\n";
  }

  return 0;
}
