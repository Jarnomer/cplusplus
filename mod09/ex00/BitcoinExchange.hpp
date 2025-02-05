#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stdexcept>

class BitcoinExchange {
private:
  std::map<std::string, double> data;

public: // constructors
  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange &other) = delete;
  BitcoinExchange &operator=(const BitcoinExchange &other) = delete;
  ~BitcoinExchange(void);

public: // methods
  void importData(const std::string &fileName);
  void printRates(const std::string &fileName);

private: // utils
  void printRate(const std::string &date, double amount) const;
  bool isValidDate(const std::string &date) const;
  bool isLeapYear(int year) const;
  bool isValidValue(double amount) const;
  const std::string trimWhiteSpace(const std::string &line) const;
  const std::string isAllDigits(const std::string &str) const;

private: // parser
  void readInput(const std::string &fileName, char delim,
                 const std::function<void(const std::string &, double)> &func);
};
