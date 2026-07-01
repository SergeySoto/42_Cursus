#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"

class Animal {
	protected:
			std::string _type;
	public:
			Animal();
			Animal(std::string name);
			Animal(const Animal& copy);
			Animal& operator=(const Animal& copy);
			virtual ~Animal();
			std::string getType() const;
			virtual void makeSound() const;
};

#endif