#include "Replace.hpp"

void	replace(std::ifstream& fd0, std::ofstream& fd1, std::string s1, std::string s2)
{
	std::string line;
	while (std::getline(fd0, line))
	{
		size_t pos = line.find(s1, 0);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
			pos = line.find(s1, pos);
		}
		fd1 << line << std::endl;
	}
}