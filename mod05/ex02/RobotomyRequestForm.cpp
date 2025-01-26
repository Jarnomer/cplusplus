#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Default", 72, 45), target("Default") {
  std::cout << "Default RobotomyRequestForm constructor was called\n\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 72, 45), target(target) {
  std::cout << "Parametric RobotomyRequestForm constructor was called\n\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy RobotomyRequestForm constructor was called\n\n";
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    target = other.target;
    AForm::operator=(other);
  }
  std::cout << "Copy RobotomyRequestForm assignment was called\n\n";
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << "Deconstructor called\n";
}

const char *RobotomyRequestForm::RobotomyException::what() const noexcept {
  return "Could not robotomize!";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 100);
  if (dist(gen) % 2 == 1) {
    std::cout << target << " has been robotomized!\n";
  } else {
    throw RobotomyRequestForm::RobotomyException();
  }
}
