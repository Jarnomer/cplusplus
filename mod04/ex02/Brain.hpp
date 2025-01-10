#pragma once

#include <iostream>
#include <string>

class Brain {
public:
  Brain(void);
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  ~Brain(void);

public:
  void setIdea(unsigned int index, std::string idea);
  std::string getIdea(unsigned int index) const;

private:
  static const unsigned int limit = 100;

protected:
  std::string ideas[limit]{};
};
