#include "Contact.hpp"

std::string Contact::get_first_name(void) { return this->first_name; }
std::string Contact::get_last_name(void) { return this->last_name; }
std::string Contact::get_nick_name(void) { return this->nick_name; }
std::string Contact::get_phone_number(void) { return this->phone_number; }
std::string Contact::get_darkest_secret(void) { return this->darkest_secret; }

void Contact::set_first_name(std::string str) { this->first_name = str; }
void Contact::set_last_name(std::string str) { this->last_name = str; }
void Contact::set_nick_name(std::string str) { this->nick_name = str; }
void Contact::set_phone_number(std::string str) { this->phone_number = str; }
void Contact::set_darkest_secret(std::string str) { this->darkest_secret = str; }

static std::string limit_output(std::string str) {
  if (str.length() > 10)
    return str.substr(0, 9) + ".";
  return str;
}

void Contact::contact_name_info(int index) {
  std::cout << "|" << std::right << std::setw(10) << index;
  std::cout << "|" << std::right << std::setw(10)
       << limit_output(this->get_first_name());
  std::cout << "|" << std::right << std::setw(10)
       << limit_output(this->get_last_name());
  std::cout << "|" << std::right << std::setw(10)
       << limit_output(this->get_nick_name());
  std::cout << "|" << std::endl;
}

void Contact::contact_full_info(void) {
  std::cout << "First Name: " << this->get_first_name() << std::endl;
  std::cout << "Last Name: " << this->get_last_name() << std::endl;
  std::cout << "Nick Name: " << this->get_nick_name() << std::endl;
  std::cout << "Phone Number: " << this->get_phone_number() << std::endl;
  std::cout << "Darkest Secret: " << this->get_darkest_secret() << std::endl;
}
