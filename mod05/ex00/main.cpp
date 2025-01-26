#include "Bureaucrat.hpp"

int main(void) {
  {
    std::cout << "Testing constructors...\n\n";
    Bureaucrat a;
    Bureaucrat b("Anon", 42);
    Bureaucrat c(b);
    a.setGrade(100);
    c = a;
    std::cout << "Deconstructors...\n\n";
  }

  std::cout << "\n";
  int grade;

  try {
    grade = 0;
    std::cout << "Testing invalid high grade: " << grade << "\n";
    Bureaucrat b("Jackson", grade);
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  try {
    grade = 151;
    std::cout << "Testing invalid low grade: " << grade << "\n";
    Bureaucrat b("Jackson", grade);
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  try {
    grade = 150;
    std::cout << "Testing decrement grade with: " << grade << "\n";
    Bureaucrat b("Jackson", grade);
    b.decrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  try {
    grade = 1;
    std::cout << "Testing increment grade with: " << grade << "\n";
    Bureaucrat b("Jackson", grade);
    b.incrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  try {
    std::cout << "Testing no error cases\n";
    Bureaucrat b("Jackson", 1);
    b.decrementGrade();
    b.setGrade(150);
    b.incrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception catched: " << e.what() << "\n\n";
  }

  return 0;
}
