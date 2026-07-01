#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << YELLOW << "Animal color" << RESET << std::endl;
	std::cout << GREEN << "Brain color" << RESET << std::endl;
	std::cout << BLUE << "Dog color" << RESET << std::endl;
	std::cout << PURPLE << "Cat color" << RESET << std::endl;
	std::cout << std::endl;

	const Animal* Animals[10];

	for (int i = 0; i <= 4; ++i)
			Animals[i] = new Dog();
	for (int j = 5; j <= 9; ++j)
			Animals[j] = new Cat();
	std::cout << "*********************************" << std::endl;
	std::cout << "*********************************" << std::endl;

	std::cout << std::endl;

	std::cout << "*********************************" << std::endl;
	std::cout << "*********************************" << std::endl;
	for (int k = 0; k <= 9; ++k)
			delete Animals[k];
	return 0;
}