#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	public:
			Dog();
			Dog(const Dog& copy);
			Dog& operator=(const Dog& copy);
			~Dog();
			void makeSound() const;
	private:
			Brain *ObjBrain;
};

#endif