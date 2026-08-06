#include "iter.hpp"

int  main() {

	std::string str[3] = {"hola", "42", "Malaga"};
	int numl[6] = {1, 2, 3, 4, 5, 6};

	iter(str, 3, printT<std::string>);
	std::cout << "-------- array de numeros original -------" << std::endl;
	iter(numl, 6, printT<int>);
	std::cout << "-------- array de numeros modificada -------" << std::endl;
	iter(numl, 6, plusOne<int>);
	iter(numl, 6, printT<int>);
	return 0;
}