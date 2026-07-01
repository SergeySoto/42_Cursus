#ifndef REPLACE_HPP
# define REPLACE_HPP

	#include <iostream>
	#include <string>
	#include <fstream>

	void	replace(std::ifstream& fd0, std::ofstream& fd1, std::string s1, std::string s2);
	int		streams(std::ifstream& fd0, std::ofstream& fd1);



#endif