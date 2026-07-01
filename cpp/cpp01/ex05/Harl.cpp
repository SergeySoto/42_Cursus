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
	for (int i = 0; i < 4; ++i)
	{
		if (lvl[i] == level)
		{
			(this->*ptr_func[i])();
			return ;
		}
	}
	std::cout << "Not found" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}