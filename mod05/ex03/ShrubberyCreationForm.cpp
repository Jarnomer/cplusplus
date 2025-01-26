#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Default", 145, 137), target("Default") {
  std::cout << "Default ShrubberyCreationForm constructor was called\n\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm(target, 145, 137), target(target) {
  std::cout << "Parametric ShrubberyCreationForm constructor was called\n\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy ShrubberyCreationForm constructor was called\n\n";
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    target = other.target;
    AForm::operator=(other);
  }
  std::cout << "Copy ShrubberyCreationForm assignment was called\n\n";
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "Deconstructor called\n";
}

const char *ShrubberyCreationForm::OutfileException::what() const noexcept {
  return "Could not create file!";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
  std::string fileName = target + "_shrubbery";
  std::ofstream outFile(fileName);
  if (outFile.is_open()) {
    outFile << "              ,@@@@@@@,\n";
    outFile << "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    outFile << "   ,&&&&%&&%,@@@@@/@@@@@@,8888888/8o\n";
    outFile << "   ,%&'\'&&%&&%,@@@@@@@/@@@88888888/88'\n";
    outFile << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888'\n";
    outFile << "   %&&%/ %&@@&&@@@ V /@@' `8888 `/88'\n";
    outFile << "  `&'\' ` /%&'    |.|       '\' '|8'\n";
    outFile << "      |o|        | |         | |\n";
    outFile << "      |.|        | |         | |\n";
    outFile << "    \\/ ._'/_/__/  ,'_//__\\/.  '_//__/_ \n";
    outFile.close();
  } else {
    throw ShrubberyCreationForm::OutfileException();
  }
}
