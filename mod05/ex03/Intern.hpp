#pragma once

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public: // constructors
  Intern(void);
  Intern(const Intern &other) = delete;
  Intern &operator=(const Intern &other) = delete;

public: // deconstructor
  ~Intern(void);

public: // methods
  AForm *makeForm(std::string name, std::string target);

private: // nested exception classes
  class FormNotFoundException : public std::exception {
    const char *what() const noexcept override;
  };
};
