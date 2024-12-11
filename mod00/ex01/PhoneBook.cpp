#include "PhoneBook.hpp"

static bool ft_valid_index(std::string str) {
  if (str.length() > 1) {
    return false;
  } else if (str == "8" || str == "9") {
    return false;
  }
  return true;
}

static bool ft_all_digits(std::string str) {
  for (char c : str)
    if (!std::isdigit(c))
      return (false);
  return (true);
}

static bool ft_empty_input(std::string str) {
  if (str.empty())
    return (true);
  for (char c : str)
    if (std::isprint(c) && !std::isspace(c))
      return (false);
  return (true);
}

static std::string get_input(std::string str) {
  std::string input;

  while (true) {
    std::cout << "Enter " << str << ": ";
    getline(std::cin, input);
    if (std::cin.eof()) {
      exit(EXIT_FAILURE);
    } else if (ft_empty_input(input)) {
      std::cout << ERR_EMPTY << std::endl;
      continue;
    }
    return input;
  }
}

static std::string get_number(std::string str) {
  std::string input;

  while (true) {
    input = get_input(str);
    if (!ft_all_digits(input)) {
      std::cout << ERR_DIGIT << std::endl;
      continue;
    }
    return input;
  }
}

static std::string get_index(std::string str) {
  std::string input;

  while (true) {
    input = get_number(str);
    if (!ft_valid_index(input)) {
      std::cout << ERR_RANGE << std::endl;
      continue;
    }
    return input;
  }
}

static void print_header(void) {
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "|" << std::left << std::setw(40)
       << "     ############CONTACTS############      ";
  std::cout << "|" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "|" << std::right << std::setw(10) << "INDEX";
  std::cout << "|" << std::right << std::setw(10) << "FIRST NAME";
  std::cout << "|" << std::right << std::setw(10) << "LAST NAME";
  std::cout << "|" << std::right << std::setw(10) << "NICK NAME";
  std::cout << "|" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::search_contact(void) {
  std::string input;
  int i;

  print_header();
  for (int i = 0; i < MAX_CONTACTS; i++) {
    this->contacts[i].contact_name_info(i);
  }
  std::cout << "---------------------------------------------" << std::endl;
  input = get_index("index");
  i = input[0] - '0';
  this->contacts[i].contact_full_info();
}

void PhoneBook::add_contact() {
  static int i = 0;

  this->contacts[i].set_first_name(get_input("first name"));
  this->contacts[i].set_last_name(get_input("last name"));
  this->contacts[i].set_nick_name(get_input("nick name"));
  this->contacts[i].set_phone_number(get_number("phone number"));
  this->contacts[i].set_darkest_secret(get_input("darkest secret"));
  i = (i + 1) % MAX_CONTACTS;
}

void PhoneBook::loop(void) {
  PhoneBook pb;
  std::string command;

  while (true) {
    std::cout << "Enter command: ";
    getline(std::cin, command);
    if (std::cin.eof()) {
      exit(EXIT_FAILURE);
    } else if (command == "EXIT") {
      exit(EXIT_SUCCESS);
    } else if (ft_empty_input(command)) {
      continue;
    } else if (command == "ADD")
      pb.add_contact();
    else if (command == "SEARCH")
      pb.search_contact();
    else
      std::cout << "Invalid command";
    std::cout << std::endl;
  }
}
