#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "variable address: " << &str << std::endl;
	std::cout << "pointer address: " << strPTR << std::endl;
	std::cout << "reference address: " << &strREF << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "variable value: " << str << std::endl;
	std::cout << "pointer value: " << *strPTR << std::endl;
	std::cout << "reference value: " << strREF << std::endl;
	return 0;
}