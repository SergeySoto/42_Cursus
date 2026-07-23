#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int t = std::rand() % 3;
	switch (t) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << RED << "Unknown type" << RESET << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (const std::exception&) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (const std::exception&) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch ( const std::exception&) {
	}
	std::cout << RED << "Unknown type" << RESET << std::endl;
}

class D : public Base {};

int main() {
	srand(time(NULL));

	std::cout << "***** ramdonObj was created *****" << std::endl;
	Base* ramdonObj = generate();
	std::cout << "***** Test identify pointer type *****" << std::endl;
	identify(ramdonObj);
	std::cout << "***** Test identify reference type *****" << std::endl;
	identify(*ramdonObj);
	delete ramdonObj;

	std::cout << "***** dObj was created *****" << std::endl;
	Base* dObj = new D();
	std::cout << "***** Test identify pointer type *****" << std::endl;
	identify(dObj);
	std::cout << "***** Test identify reference type *****" << std::endl;
	identify(*dObj);
	delete dObj;

	return 0;
}