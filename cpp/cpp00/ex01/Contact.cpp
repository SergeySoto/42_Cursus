/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:37:50 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/26 16:37:51 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void Contact::setName(std::string input)
{
	this->_firstName = input;
}

void Contact::setLastName(std::string input)
{
	this->_lastName = input;
}

void Contact::setNickName(std::string input)
{
	this->_nickName = input;
}

void Contact::setPhoneNumber(std::string input)
{
	this->_phoneNumber = input;
}

void Contact::setDarkestSecret(std::string input)
{
	this->_darkestSecret = input;
}