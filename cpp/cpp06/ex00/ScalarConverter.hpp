#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cerrno>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();
	public:
		static void convert(const std::string& str);
};

#endif