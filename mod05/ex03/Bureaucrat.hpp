#pragma once

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {
private:
  const std::string name;
  int grade;

private:
  const int lowerLimit = 150;
  const int upperLimit = 1;

public: // constructors
  Bureaucrat(void);
  Bureaucrat(const std::string &name, const int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

public: // deconstructor
  ~Bureaucrat(void);

public: // getters
  std::string getName(void) const noexcept;
  int getGrade(void) const noexcept;

public: // setters
  void setGrade(const int grade);

public: // mutators
  void decrementGrade(void);
  void incrementGrade(void);

public: // methods
  void signForm(AForm &form) const;
  void executeForm(AForm const &form);

private: // nested exception classes
  class GradeTooHighException : public std::exception {
    const char *what() const noexcept override;
  };
  class GradeTooLowException : public std::exception {
    const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &person);
