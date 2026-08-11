#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

class BitcoinExchange {
	private:
		std::map <std::string, float> mapBit;
		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &valStr);
		std::string trim(const std::string &str);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
		bool loadDataBase(const std::string &db);
		void bitCoinCalculator(const std::string &file);
};

#endif