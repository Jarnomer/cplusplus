#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
private:
  bool isSigned = false;
  const std::string name;
  const int signGrade;
  const int execGrade;

private:
  const int lowerLimit = 150;
  const int upperLimit = 1;

public: // constructors
  AForm(void);
  AForm(const std::string &name, const int sign, const int exec);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);

public: // deconstructor
  virtual ~AForm(void);

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
  class FormNotSignedException : public std::exception {
    const char *what() const noexcept override;
  };

public: // virtual function
  virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
