#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  {
    std::cout << "Testing constructors...\n\n";
    Form f;
    Form g("Illegal", 88, 1);
    Form i(g);
    i.setIsSigned(true);
    f = i;
    std::cout << "Deconstructors...\n\n";
  }

  std::cout << "\n";
  int grade;

  try {
    grade = 151;
    std::cout << "Testing invalid low grade: " << grade << "\n";
    Form f("Illegal", grade, 1);
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  try {
    grade = 0;
    std::cout << "Testing invalid high grade: " << grade << "\n";
    Form f("Illegal", 1, grade);
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  try {
    grade = 100;
    std::cout << "Testing invalid sign grade: " << grade << "\n";
    Bureaucrat b("Jackson", grade);
    Form f("Illegal", grade - 1, grade);
    b.signForm(f);
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  std::cout << "\n";

  try {
    grade = 100;
    std::cout << "Testing valid sign grade: " << grade << "\n";
    Bureaucrat b("Jackson", grade);
    Form f("Illegal", grade + 1, grade);
    b.signForm(f);
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  return 0;
}
