#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"


class Cure : public AMateria{
		public:
			Cure();
			Cure(const Cure& copy);
			Cure& operator=(const Cure& copy);
			~Cure();
			virtual AMateria* clone() const;
			virtual void use(ICharacter& target);
};

#endif