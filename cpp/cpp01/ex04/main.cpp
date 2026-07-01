#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong arguments." << std::endl;
		return 1;
	}
	std::ifstream _input(av[1]);
	std::string n_file = av[1];
	n_file += ".replace";
	std::ofstream _output(n_file.c_str());
	if (streams(_input, _output))
		return 1;
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty() || s1.empty())
		return 1;
	replace(_input, _output, s1, s2);
	return 0;
}
