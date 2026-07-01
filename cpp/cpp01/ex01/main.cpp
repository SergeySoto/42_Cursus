#include "Zombie.hpp"
#include <limits>

int main(void)
{
	std::string name;
	int num;
	Zombie *horde;
	std::cout << "-- Zombie horde machine --" << std::endl;
	do {
		std::cout << "Insert a number of zombies: ";
		std::cin >> num;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Insert a valid number." << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (num > 0)
				break ;
			else
				std::cout << "Insert a number greater than 0." << std::endl;
		}
	} while (true);
	do {
		std::cout << "Insert a name for the zombies: ";
		std::getline(std::cin, name);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
	} while (std::cin.fail());
	horde = zombieHorde(num, name);
	for (int i = 0; i < num; ++i)
		horde[i].announce();
	delete[] horde;
	return 0;
}
