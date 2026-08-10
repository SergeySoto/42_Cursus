#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	this->mapBit = copy.mapBit;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		this->mapBit = copy.mapBit;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDataBase(const std::string &db) {
	std::ifstream file(db.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		std::string date = line.substr(0, pos);
		std::string flt = line.substr(pos + 1);
		std::istringstream conversionStream(flt);
		float num;
		if (conversionStream >> num) {
			this->mapBit[date] = num;
		}
	}
	return true;
}

void BitcoinExchange::bitCoinCalculator(const std::string& file) {
	std::ifstream fl(file.c_str());
	if (!fl.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(fl, line);
	while (std::getline(fl, line)) {
		std::string::size_type pos = line.find(" | ");
		if (pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 3);
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (!isValidValue(valueStr))
			continue ;
		std::map<std::string, float>::iterator it;
		it = mapBit.upper_bound(date);
		if (it == mapBit.begin()) {
			std::cerr << "Date too old" << std::endl; 
			continue ;
		}
		--it;
		float num;
		std::istringstream ssnum(valueStr);
		ssnum >> num;
		std::cout << date << " => " << num << " = " << num * it->second << std::endl;
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	std::string::size_type pos1 = date.find('-');
	if (pos1 == std::string::npos) return false;
	std::string stryear = date.substr(0, pos1);
	std::string::size_type pos2 = date.find('-', pos1 + 1);
	if (pos2 == std::string::npos) return false;
	std::string strmonth = date.substr(pos1 + 1, pos2 - (pos1 + 1));
	std::string strday = date.substr(pos2 + 1);
	int year;
	int month;
	int day;
	std::istringstream ssyear(stryear);
	if (!(ssyear >> year) || !ssyear.eof()) return false;
	std::istringstream ssmonth(strmonth);
	if (!(ssmonth >> month) || !ssmonth.eof()) return false;
	std::istringstream ssday(strday);
	if (!(ssday >> day) || !ssday.eof()) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
	if (month == 2) {
		bool isLeap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		if (isLeap) 
			if (day > 29)
				return false;
		else
			if (day > 28)
				return false;
	}
	//if returns false it should print error message
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valStr) {
	float num;
	std::istringstream ssnum(valStr);
	if (!(ssnum >> num) || !ssnum.eof()) return false;
	if (num < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (num > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}