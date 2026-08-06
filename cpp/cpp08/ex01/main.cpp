#include "Span.hpp"

#include <cstdlib>

int main()
{
	srand(time(NULL));
	Span sp1 = Span(5);
	std::cout << "First test" << std::endl;
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	//--------------------------------------------
	try {
		std::cout << "Second test" << std::endl;
		Span sp2 = Span(3);
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
		sp2.addNumber(4); //Error
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Third test" << std::endl;
		Span sp3 = Span(10);
		std::cout << sp3.shortestSpan() << std::endl; //Error
		std::cout << sp3.longestSpan() << std::endl; //Error
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Fourth test" << std::endl;
		Span sp4 = Span(15000);
		for (int i = 0; i < 10000; ++i)
			sp4.addNumber(rand());
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Fifth test" << std::endl;
		std::vector<int> myvect;
		for (int i = 0; i < 2000; ++i)
			myvect.push_back(rand());
		Span sp5(1000);
		sp5.addRange(myvect.begin(), myvect.end()); //Error
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}