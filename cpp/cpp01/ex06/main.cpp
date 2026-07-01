#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	std::string str = av[1];
	if (str.empty())
		return 1;
	Harl Harll;
	Harll.complain(str);
	// Harll.complain("INFO");
	// Harll.complain("WARNING");
	// Harll.complain("ERROR");
	return 0;
}