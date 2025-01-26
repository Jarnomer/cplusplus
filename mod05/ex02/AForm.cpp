#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : name("Form"), signGrade(42), execGrade(42) {
  std::cout << "Default AForm constructor called\n" << *this;
}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade)
    : name(name), signGrade(signGrade), execGrade(execGrade) {
  std::cout << "Parametric AForm constructor called\n" << *this;
  if (signGrade > lowerLimit || execGrade > lowerLimit) {
    throw AForm::GradeTooLowException();
  } else if (signGrade < upperLimit || execGrade < upperLimit) {
    throw AForm::GradeTooHighException();
  }
}

AForm::AForm(const AForm &other)
    : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
  this->setIsSigned(other.isSigned);
  std::cout << "Copy AForm constructor called\n" << *this;
}

AForm &AForm::operator=(const AForm &other) {
  std::cout << "Copy AForm assigment called\n";
  if (this != &other) {
    this->setIsSigned(other.isSigned);
  }
  std::cout << *this;
  return *this;
}

AForm::~AForm(void) { std::cout << "Deconstructor called\n"; }

std::string AForm::getName(void) const noexcept { return name; }

int AForm::getSignGrade(void) const noexcept { return signGrade; }

int AForm::getExecGrade(void) const noexcept { return execGrade; }

bool AForm::getIsSigned(void) const noexcept { return isSigned; }

void AForm::setIsSigned(const bool value) noexcept { isSigned = value; }

void AForm::beSigned(const Bureaucrat &person) {
  int grade = person.getGrade();
  std::cout << "Form beSigned: " << signGrade << " vs: " << grade << "\n";
  if (grade > signGrade) {
    throw AForm::GradeTooLowException();
  } else {
    isSigned = true;
  }
}

const char *AForm::GradeTooHighException::what() const noexcept {
  return "Requirement too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return "Requirement too low!";
}

const char *AForm::FormNotSignedException::what() const noexcept {
  return "Form is not signed!";
}

void AForm::execute(Bureaucrat const &executor) const {
  if (!isSigned) {
    throw AForm::FormNotSignedException();
  } else if (execGrade < executor.getGrade()) {
    throw AForm::GradeTooLowException();
  }
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form Name: " << form.getName() << "\n";
  os << "Form Sign Grade: " << form.getSignGrade() << "\n";
  os << "Form Exec Grade: " << form.getExecGrade() << "\n";
  os << "Form is Signed: " << form.getIsSigned() << "\n\n";
  return os;
}
