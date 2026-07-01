#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
	protected:
			std::string _type;
	public:
			WrongAnimal();
			WrongAnimal(std::string name);
			WrongAnimal(const WrongAnimal& copy);
			WrongAnimal& operator=(const WrongAnimal& copy);
			~WrongAnimal();
			std::string getType() const;
			void makeSound() const;
};

#endif