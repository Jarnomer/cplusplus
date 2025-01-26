#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  {
    std::cout << "Testing constructors...\n";
    std::cout << "========================================\n";
    ShrubberyCreationForm s;
    ShrubberyCreationForm t("Unique");
    ShrubberyCreationForm u(s);
    u = t;
    std::cout << "Deconstructors...\n\n";
  }

  int grade;
  std::cout << "========================================\n\n";

  {
    grade = 100;
    std::cout << "Testing unsigned Shrubbery Creation Form\n";
    std::cout << "========================================\n";
    Bureaucrat b("Jackson", grade);
    ShrubberyCreationForm f("Illegal");
    try {
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
    std::cout << "\n";
  }

  std::cout << "========================================\n\n";

  {
    grade = 140;
    std::cout << "Testing invalid Shrubbery Creation Form: " << grade << "\n";
    std::cout << "========================================\n";
    Bureaucrat b("Jackson", grade);
    ShrubberyCreationForm f("Illegal");
    try {
      b.signForm(f);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
    std::cout << "\n";
  }

  std::cout << "========================================\n\n";

  {
    grade = 5;
    std::cout << "Testing valid Presidential Pardon Form: " << grade << "\n";
    std::cout << "========================================\n";
    Bureaucrat b("Jackson", grade);
    PresidentialPardonForm f("Donald Trump");
    try {
      b.signForm(f);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
    std::cout << "\n";
  }

  std::cout << "========================================\n\n";

  {
    grade = 45;
    std::cout << "Testing valid Robotomy Request Form: " << grade << "\n";
    std::cout << "========================================\n";
    Bureaucrat b("Jackson", grade);
    RobotomyRequestForm f("Robocop");
    try {
      b.signForm(f);
      b.executeForm(f);
    } catch (std::exception &e) {
      std::cout << "Exception catched: " << e.what() << "\n\n";
    }
  }

  return 0;
}
