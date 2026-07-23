#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

static bool isPseudoLiteral(const std::string& str) {
	if ("-inff" == str || "+inff" == str || "nanf" == str || "-inf" == str || "+inf" == str || "nan" == str)
		return true;
	else
		return false;
}

static bool isChar(const std::string& str) {
	if (str.length() == 1 && !isdigit(static_cast<int>(str[0])))
		return true;
	else
		return false;
}

static bool isInt(const std::string& str) {
	char* endptr = NULL;
	errno = 0;
	long num = strtol(str.c_str(), &endptr, 10);
	if (errno == ERANGE)
		return false;
	else if (str.c_str() == endptr)
		return false;
	else if (num > std::numeric_limits<int>::max())
		return false;
	else if (num < std::numeric_limits<int>::min())
		return false;
	else {
		if (*endptr == '\0')
			return true;
		return false;
	}
}

static bool isFloat(const std::string& str) {
	char* endptr = NULL;
	errno = 0;
	strtof(str.c_str(), &endptr);
	if (errno == ERANGE)
		return false;
	else if (str.c_str() == endptr)
		return false;
	else {
		if (*endptr == 'f' && endptr[1] == '\0')
			return true;
		return false;
	}
}

static bool isDouble(const std::string& str) {
	char* endptr = NULL;
	errno = 0;
	strtod(str.c_str(), &endptr);
	if (errno == ERANGE)
		return false;
	else if (str.c_str() == endptr)
		return false;
	else {
		if (*endptr == '\0')
			return true;
		return false;
	}
}

static void printPseudoLit(const std::string& str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nanf" || str == "+inff" || str == "-inff") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	}
	else {
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

static void printChar(const std::string& str) {
	char ch = str[0];
	if (ch > 127 || ch < 0)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(ch))) {
		char c = static_cast<char>(ch);
		std::cout << "char: " << '\'' << c << '\'' << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	int numint = static_cast<int>(ch);
	std::cout << "int: " << numint << std::endl;
	float numftl = static_cast<float>(ch);
	std::cout << "float: " << std::fixed << std::setprecision(1) << numftl << "f" <<  std::endl;
	double numdbl = static_cast<double>(ch);
	std::cout << "double: " << std::setprecision(1) << numdbl << std::endl;
}

static void printInt(const std::string& str) {
	char* endptr = NULL;
	long num = strtol(str.c_str(), &endptr, 10);
	if (num > 127 || num < 0)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(num))) {
		char c = static_cast<char>(num);
		std::cout << "char: " << '\'' << c << '\'' << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	int numint = static_cast<int>(num);
	std::cout << "int: " << numint << std::endl;
	float numflt = static_cast<float>(num);
	std::cout << "float: " << std::fixed << std::setprecision(1) << numflt << "f" << std::endl;
	double numdbl = static_cast<double>(num);
	std::cout << "double: " << std::setprecision(1) << numdbl << std::endl;
}

static void printFloat(const std::string& str) {
	char* endptr = NULL;
	float num = strtof(str.c_str(), &endptr);
	if (num > 127 || num < 0)
		std::cout << "char: impossible" <<std::endl;
	else if (isprint(static_cast<int>(num))) {
		char c = static_cast<int>(num);
		std::cout << "char: " << '\'' << c << '\'' << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else {
		int numint = static_cast<int>(num);
		std::cout << "int: " << numint << std::endl;
	}
	float numflt = static_cast<float>(num);
	std::cout << "float: " << std::fixed << std::setprecision(1) << numflt << 'f' << std::endl;
	double numdbl = static_cast<double>(num);
	std::cout << "double: " << std::setprecision(1) << numdbl << std::endl;
}

static void printDouble(const std::string& str) {
	char* endptr = NULL;
	double num = strtod(str.c_str(), &endptr);
	if (num > 127 || num < 0)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(num))) {
		char c = static_cast<char>(num);
		std::cout << "char: " << '\'' << c << '\'' << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else {
		int numint = static_cast<int>(num);
		std::cout << "int: " << numint << std::endl;
	}
	float numflt = static_cast<float>(num);
	std::cout << "float: " << std::fixed << std::setprecision(1) << numflt << "f" << std::endl;
	double numdbl = static_cast<double>(num);
	std::cout << "double: " << std::setprecision(1) << numdbl << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	if (isPseudoLiteral(str)) {
		printPseudoLit(str);
		return ;
	}
	if (isChar(str)) {
		printChar(str);
		return ;
	}
	if (isInt(str)) {
		printInt(str);
		return ;
	}
	if (isFloat(str)) {
		printFloat(str);
		return ;
	}
	if (isDouble(str)) {
		printDouble(str);
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}