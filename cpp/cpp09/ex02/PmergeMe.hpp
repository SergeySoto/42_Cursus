#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <string>
#include <ctime>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _deq;
		void fordJohnson(std::vector<unsigned int> &container);
		void fordJohnson(std::deque<unsigned int> &container);
		bool extractNumber(const std::string &num);
		void printContainer(const std::vector<unsigned int> &container);
		std::vector<std::pair<unsigned int, unsigned int> > newVecPair(std::vector<unsigned int> &container);
		std::vector<size_t> generateJacob(size_t limit);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
		~PmergeMe();
		bool process(int ac, char** av);
};

#endif