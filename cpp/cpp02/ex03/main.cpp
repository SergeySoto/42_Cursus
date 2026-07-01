#include <iostream>
#include "Point.hpp"

int main( void ) {

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);


	Point p_inside(2.0f, 2.0f);   // IN
	Point p_outside(10.0f, 10.0f); // OUT
	Point p_edge(5.0f, 0.0f);     // OUT
	Point p_vertex(0.0f, 0.0f);   // OUT

	std::cout << "\n=============================================" << std::endl;
	std::cout << "          TRIANGLE: (0,0), (10,0), (0,10)" << std::endl;
	std::cout << "=============================================\n" << std::endl;

	std::cout << "Test 1: Point (2, 2) -> ";
	if (bsp(a, b, c, p_inside))
		std::cout << "\033[32m[ IN ]\033[0m" << std::endl;
	else
		std::cout << "\033[31m[ OUT ]\033[0m" << std::endl;

	std::cout << "Test 2: Point (10, 10) -> ";
	if (bsp(a, b, c, p_outside))
		std::cout << "\033[32m[ IN ]\033[0m" << std::endl;
	else
		std::cout << "\033[31m[ OUT ]\033[0m" << std::endl;

	std::cout << "Test 3: Point (5, 0) -> ";
	if (bsp(a, b, c, p_edge))
		std::cout << "\033[32m[ IN ]\033[0m" << std::endl;
	else
		std::cout << "\033[31m[ OUT ]\033[0m" << std::endl;

	std::cout << "Test 4: Point (0, 0) -> ";
	if (bsp(a, b, c, p_vertex))
		std::cout << "\033[32m[ IN ]\033[0m" << std::endl;
	else
		std::cout << "\033[31m[ OUT ]\033[0m" << std::endl;

	std::cout << "\n=============================================\n" << std::endl;

	return 0;
}