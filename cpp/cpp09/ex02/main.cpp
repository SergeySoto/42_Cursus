#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2)
		std::cerr << "Error" << std::endl;
	PmergeMe merge;
	if (!merge.process(ac, av))
		return 1;
	return 0;
}