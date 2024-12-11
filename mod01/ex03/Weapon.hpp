#pragma once

#include <string>

class Weapon {
private:
  std::string type;

public:
  Weapon(std::string type);
  void setType(std::string type);
  const std::string &getType(void);
};
