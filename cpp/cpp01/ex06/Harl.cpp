#include "Harl.hpp"

Harl::Harl() {
	ptr_func[0] = &Harl::debug;
	ptr_func[1] = &Harl::info;
	ptr_func[2] = &Harl::warning;
	ptr_func[3] = &Harl::error;
}

Harl::~Harl() {

}

void Harl::complain(std::string level)
{
	std::string lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR" };
	int i;
	for (i = -1; i < 4; ++i)
	{
		if (lvl[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
			(this->*ptr_func[0])();
		case 1:
			(this->*ptr_func[1])();
		case 2:
			(this->*ptr_func[2])();
		case 3:
		{
			(this->*ptr_func[3])();
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return ;
		}
	}
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}