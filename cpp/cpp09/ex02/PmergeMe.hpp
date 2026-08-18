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
#include <iomanip>

class PmergeMe {
	private:
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _deq;
		void fordJohnson(std::vector<unsigned int> &container);
		void fordJohnson(std::deque<unsigned int> &container);
		bool extractNumber(const std::string &num);
		void printContainer(const std::vector<unsigned int> &container);
		void printContainer(const std::deque<unsigned int> &container);
		std::vector<std::pair<unsigned int, unsigned int> > newVecPair(std::vector<unsigned int> &container);
		std::deque<std::pair<unsigned int, unsigned int> > newVecPair(std::deque<unsigned int> &container);
		std::vector<size_t> generateJacob(size_t limit, std::vector<unsigned int> &container);
		std::deque<size_t> generateJacob(size_t limit, std::deque<unsigned int> &container);
		std::vector<unsigned int> jacobsthal(std::vector<unsigned int> &winners, std::vector<unsigned int> &pend,
			bool &hasOdd, unsigned int &oddVal);
		std::deque<unsigned int> jacobsthal(std::deque<unsigned int> &winners, std::deque<unsigned int> &pend,
			bool &hasOdd, unsigned int &oddVal);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
		~PmergeMe();
		bool process(int ac, char** av);
};

#endif