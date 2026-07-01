#include "Replace.hpp"

int	streams(std::ifstream& fd0, std::ofstream& fd1)
{
	if (!fd0.is_open())
	{
		std::cout << "Input opening failed." << std::endl;
		return 1;
	}
	if (!fd1.is_open())
	{
		std::cout << "Output opening failed." << std::endl;
		return 1;
	}
	return 0;
}