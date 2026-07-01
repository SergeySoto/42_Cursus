#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"

int main()
{
	std::cout << YELLOW << "--- 1. Initialize source of magic ---" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << GREEN << "\n--- 2. Creating characters ---" << RESET << std::endl;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	std::cout << BLUE << "\n--- 3. Equip and use magic ---" << RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << PURPLE << "\n--- 4. Inventory full and out of range ---" << RESET << std::endl;
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	AMateria* extra = src->createMateria("ice");
	me->equip(extra);
	delete extra;

	me->use(4, *bob); 
	me->use(-1, *bob); 

	std::cout << YELLOW << "\n--- 6. Probando Copia Profunda ---" << RESET << std::endl;
	Character original("Original");
	original.equip(src->createMateria("cure"));

	Character copia = original;
	copia.use(0, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
