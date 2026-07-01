/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:37:37 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/26 18:59:44 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact _phoneBook[8];
	int _index;
	int _count;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(void);
	void	searchContact(void) const;
	bool getInput(std::string prompt, std::string &str);
};

#endif