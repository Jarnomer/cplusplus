#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Bureaucrat") {
  std::cout << "Default constructor called\n";
  setGrade(lowerLimit);
  std::cout << *this;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name(name) {
  std::cout << "Parametric constructor called\n";
  setGrade(grade);
  std::cout << *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  std::cout << "Copy constructor called\n";
  std::cout << *this;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Copy assigment called\n";
  if (this != &other) {
    grade = other.grade;
  }
  std::cout << *this;
  return *this;
}

Bureaucrat::~Bureaucrat(void) { std::cout << "Deconstructor called\n"; }

std::string Bureaucrat::getName(void) const noexcept { return name; }

int Bureaucrat::getGrade(void) const noexcept { return grade; }

void Bureaucrat::setGrade(const int grade) {
  std::cout << "Bureaucrat setGrade: " << grade << "\n";
  if (grade > lowerLimit) {
    throw Bureaucrat::GradeTooLowException();
  } else if (grade < upperLimit) {
    throw Bureaucrat::GradeTooHighException();
  } else {
    this->grade = grade;
  }
}

void Bureaucrat::incrementGrade(void) {
  std::cout << "Increment ";
  setGrade(--grade);
}

void Bureaucrat::decrementGrade(void) {
  std::cout << "Decrement ";
  setGrade(++grade);
}

void Bureaucrat::signForm(AForm &form) const {
  std::string fname = form.getName();
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << fname << "\n";
  } catch (std::exception &e) {
    std::cout << name << " couldn't sign " << fname << ": " << e.what() << "\n";
  }
}

void Bureaucrat::executeForm(const AForm &form) {
  std::string fname = form.getName();
  try {
    form.execute(*this);
    std::cout << name << " executed " << fname << "\n";
  } catch (std::exception &e) {
    std::cout << name << " couldn't execute " << fname << ": " << e.what()
              << "\n";
  }
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &person) {
  os << "Bureaucrat Name: " << person.getName() << "\n";
  os << "Bureaucrat Grade: " << person.getGrade() << "\n\n";
  return os;
}
