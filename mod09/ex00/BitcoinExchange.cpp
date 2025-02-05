#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::readInput(
    const std::string &fileName, char delim,
    const std::function<void(const std::string &, double)> &import_or_print) {
  std::ifstream input(fileName);
  std::string line, date, value;
  if (input.is_open()) {
    std::getline(input, line); // header
    while (std::getline(input, line)) {
      std::istringstream readLine(line);
      if (!std::getline(readLine, date, delim) ||
          !std::getline(readLine, value)) {
        std::cerr << "Invalid line format: " << line << "\n";
      } else if (isValidDate(trimWhiteSpace(date))) {
        try {
          double amount = std::stod(isAllDigits(trimWhiteSpace(value)));
          import_or_print(date, amount);
        } catch (const std::invalid_argument &e) {
          std::cerr << "Invalid argument:" << value << "\n";
        } catch (const std::out_of_range &e) {
          std::cerr << "Out of range:" << value << "\n";
        }
      }
    }
    input.close();
  } else {
    throw std::runtime_error("Failed to open file: " + fileName);
  }
}

void BitcoinExchange::printRate(const std::string &date, double amount) const {
  if (!isValidValue(amount)) {
    return;
  } else {
    auto it = data.upper_bound(date);
    if (it == data.begin()) {
      std::cerr << "No date found: " << date << "\n";
      return;
    } else {
      auto [targetDate, targetRate] = *(--it);
      std::cout << targetDate << " => " << amount << " = "
                << amount * targetRate << "\n";
    }
  }
}

void BitcoinExchange::printRates(const std::string &fileName) {
  readInput(fileName, '|', [this](const std::string &date, double amount) {
    printRate(date, amount);
  });
}

void BitcoinExchange::importData(const std::string &fileName) {
  readInput(fileName, ',', [this](const std::string &date, double amount) {
    data.emplace(date, amount);
  });
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  std::regex pattern(R"((\d{4})-(\d{2})-(\d{2}))");
  std::smatch match;
  if (!std::regex_match(date, match, pattern)) {
    std::cerr << "Invalid date: " << date << "\n";
    return false;
  } else {
    int year = std::stoi(match[1].str());
    int month = std::stoi(match[2].str());
    int day = std::stoi(match[3].str());
    int days[] = {31, (isLeapYear(year) ? 29 : 28),
                  31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12 || day < 1 || day > days[month - 1]) {
      std::cerr << "Invalid date: " << date << "\n";
      return false;
    } else {
      return true;
    }
  }
}

bool BitcoinExchange::isValidValue(double amount) const {
  if (amount > 1000 || amount < 0) {
    std::cerr << "Amount out of range: " << amount << "\n";
    return false;
  } else {
    return true;
  }
}

bool BitcoinExchange::isLeapYear(int year) const {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

const std::string BitcoinExchange::trimWhiteSpace(const std::string &str) const {
  return std::regex_replace(str, std::regex("^[ \t]+|[ \t]+$"), "");
}

const std::string BitcoinExchange::isAllDigits(const std::string &str) const {
  std::regex pattern("^[0-9]+(\\.[0-9]+)?$");
  if (!std::regex_match(str, pattern)) {
    throw std::invalid_argument("");
  } else {
    return str;
  }
}
