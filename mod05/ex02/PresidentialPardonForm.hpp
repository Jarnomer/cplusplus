#pragma once

#include "AForm.hpp"

#include <iostream>

class PresidentialPardonForm : public AForm {
private:
  std::string target;

public: // constructors
  PresidentialPardonForm(void);
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

public: // deconstructor
  ~PresidentialPardonForm(void);

public: // override function
  void execute(Bureaucrat const &executor) const override;
};
