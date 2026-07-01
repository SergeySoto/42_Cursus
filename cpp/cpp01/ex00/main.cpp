#include "Zombie.hpp"

int main(void)
{
	Zombie *Foo1 = newZombie("Foo1");
	Foo1->announce();
	randomChump("Boo2");
	delete Foo1;
	return 0;
}
