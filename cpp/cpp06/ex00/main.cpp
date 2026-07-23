#include "ScalarConverter.hpp"

int main(int ac, char* av[]) {
	if (ac != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(av[1]));
	return 0;
}