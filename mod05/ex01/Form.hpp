#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
private:
  bool isSigned = false;
  const std::string name;
  const int signGrade;
  const int execGrade;

private:
  const int lowerLimit = 150;
  const int upperLimit = 1;

public: // constructors
  Form(void);
  Form(const std::string &name, const int sign, const int exec);
  Form(const Form &other);
  Form &operator=(const Form &other);

public: // deconstructor
  ~Form(void);

public: // getters
  std::string getName(void) const noexcept;
  int getSignGrade(void) const noexcept;
  int getExecGrade(void) const noexcept;
  bool getIsSigned(void) const noexcept;

public: // mutators
  void setIsSigned(const bool value) noexcept;
  void beSigned(const Bureaucrat &person);

private: // nested exception classes
  class GradeTooHighException : public std::exception {
    const char *what() const noexcept override;
  };
  class GradeTooLowException : public std::exception {
    const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);
