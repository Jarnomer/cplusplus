#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void) : name("Form"), signGrade(42), execGrade(42) {
  std::cout << "Default constructor called\n" << *this;
}

Form::Form(const std::string &name, const int signGrade, const int execGrade)
    : name(name), signGrade(signGrade), execGrade(execGrade) {
  std::cout << "Parametric constructor called\n" << *this;
  if (signGrade > lowerLimit || execGrade > lowerLimit) {
    throw Form::GradeTooLowException();
  } else if (signGrade < upperLimit || execGrade < upperLimit) {
    throw Form::GradeTooHighException();
  }
}

Form::Form(const Form &other)
    : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
  this->setIsSigned(other.isSigned);
  std::cout << "Copy constructor called\n" << *this;
}

Form &Form::operator=(const Form &other) {
  std::cout << "Copy assigment called\n";
  if (this != &other) {
    this->setIsSigned(other.isSigned);
  }
  std::cout << *this;
  return *this;
}

Form::~Form(void) { std::cout << "Deconstructor called\n"; }

std::string Form::getName(void) const noexcept { return name; }

int Form::getSignGrade(void) const noexcept { return signGrade; }

int Form::getExecGrade(void) const noexcept { return execGrade; }

bool Form::getIsSigned(void) const noexcept { return isSigned; }

void Form::setIsSigned(const bool value) noexcept { isSigned = value; }

void Form::beSigned(const Bureaucrat &person) {
  int grade = person.getGrade();
  std::cout << "Form beSigned: " << signGrade << " vs: " << grade << "\n";
  if (grade > signGrade) {
    throw Form::GradeTooLowException();
  } else {
    isSigned = true;
  }
}

const char *Form::GradeTooHighException::what() const noexcept {
  return "Requirement too high!";
}

const char *Form::GradeTooLowException::what() const noexcept {
  return "Requirement too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form Name: " << form.getName() << "\n";
  os << "Form Sign Grade: " << form.getSignGrade() << "\n";
  os << "Form Exec Grade: " << form.getExecGrade() << "\n";
  os << "Form is Signed: " << form.getIsSigned() << "\n\n";
  return os;
}
