/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:37:31 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/26 18:54:52 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_count = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool PhoneBook::getInput(std::string prompt, std::string &str)
{
	do {
		std::cout << prompt;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return false;
		}
	} while (str.empty());
	return true;
}

void PhoneBook::addContact(void)
{
	std::string temp;
	do {
		std::cout << "First name: ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	} while (temp.empty());
	_phoneBook[_index].setName(temp);
	do {
		std::cout << "Last name: ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	} while (temp.empty());
	_phoneBook[_index].setLastName(temp);
	do {
		std::cout << "Nick name: ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	} while (temp.empty());
	_phoneBook[_index].setNickName(temp);
	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	} while (temp.empty());
	_phoneBook[_index].setPhoneNumber(temp);
	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, temp);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	} while (temp.empty());
	_phoneBook[_index].setDarkestSecret(temp);
	_index = (_index + 1) % 8;
	if (_count < 8)
		++_count;
}

void PhoneBook::searchContact(void) const
{
	std::string str;
	for (int i = 0; i < _count; ++i)
	{
		std::cout << std::setw(10) << i << "|";
		str = this->_phoneBook[i].getName();
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str << "|";
		str = this->_phoneBook[i].getLastName();
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str << "|";
		str = this->_phoneBook[i].getNickName();
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str << "|" << std::endl;
	}
	std::cout << "Enter index to display: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
		std::cout << std::endl;
	if (str.length() == 1)
	{
		int num = str[0] - '0';
		if (num < 0 || num >= _count)
			std::cout << "Number out of range!!!" << std::endl;
		else
		{
			std::cout << this->_phoneBook[num].getName() << std::endl;
			std::cout << this->_phoneBook[num].getLastName() << std::endl;
			std::cout << this->_phoneBook[num].getNickName() << std::endl;
			std::cout << this->_phoneBook[num].getPhoneNumber() << std::endl;
			std::cout << this->_phoneBook[num].getDarkestSecret() << std::endl;
		}
	}
	else
		std::cout << "Number out of range!!!" << std::endl;
}
