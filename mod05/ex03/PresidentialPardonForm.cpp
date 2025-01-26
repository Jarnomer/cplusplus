#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Default", 25, 5), target("Default") {
  std::cout << "Default PresidentialPardonForm constructor was called\n\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5), target(target) {
  std::cout << "Parametric PresidentialPardonForm constructor was called\n\n";
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy PresidentialPardonForm constructor was called\n\n";
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    target = other.target;
    AForm::operator=(other);
  }
  std::cout << "Copy PresidentialPardonForm assignment was called\n\n";
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << "Deconstructor called\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::cout << target << " has been pardoned by Zaphod Beeblebrox!\n";
}
