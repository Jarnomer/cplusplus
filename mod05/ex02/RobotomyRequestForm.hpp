#pragma once

#include "AForm.hpp"

#include <iostream>
#include <random>

class RobotomyRequestForm : public AForm {
private:
  std::string target;

public: // constructors
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

public: // deconstructor
  ~RobotomyRequestForm(void);

private: // nested exception classes
  class RobotomyException : public std::exception {
    const char *what() const noexcept override;
  };

public: // override function
  void execute(Bureaucrat const &executor) const override;
};
