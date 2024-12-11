#pragma once

#include <iomanip>
#include <iostream>

class Contact {
private:
  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

public:
  std::string get_first_name(void);
  std::string get_last_name(void);
  std::string get_nick_name(void);
  std::string get_phone_number(void);
  std::string get_darkest_secret(void);
  void set_first_name(std::string str);
  void set_last_name(std::string str);
  void set_nick_name(std::string str);
  void set_phone_number(std::string str);
  void set_darkest_secret(std::string str);
  void contact_name_info(int index);
  void contact_full_info(void);
};
