#pragma once

#include "AForm.hpp"

#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;

public: // constructors
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

public: // deconstructor
  ~ShrubberyCreationForm(void);

private: // nested exception classes
  class OutfileException : public std::exception {
    const char *what() const noexcept override;
  };

public: // override function
  void execute(Bureaucrat const &executor) const override;
};
