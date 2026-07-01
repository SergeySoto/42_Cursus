#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"

class AAnimal {
	protected:
			std::string _type;
	public:
			AAnimal();
			AAnimal(std::string name);
			AAnimal(const AAnimal& copy);
			AAnimal& operator=(const AAnimal& copy);
			virtual ~AAnimal();
			std::string getType() const;
			virtual void makeSound() const = 0;
};

#endif