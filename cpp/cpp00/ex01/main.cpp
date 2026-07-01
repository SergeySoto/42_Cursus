/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:37:42 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/26 16:37:43 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneNumber;
	std::string str;
	while (1)
	{
		std::cout << "Program commands. ADD, SEARCH and EXIT" << std::endl << ">";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
		if (str == "ADD")
			phoneNumber.addContact();
		else if (str == "SEARCH")
			phoneNumber.searchContact();
		else if (str == "EXIT")
		{
			std::cout << std::endl;
			return 0;
		}
		else
			std::cout << "Wrong command please try again." << std::endl;
	}
	return 0;
}
