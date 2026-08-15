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

class PmergeMe {
	private:
		std::string unsorted;
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _deq;
		void fordJohnson(std::vector<unsigned int> &container);
		void fordJohnson(std::deque<unsigned int> &container);
		bool isValidNumber(const std::string &num);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
		~PmergeMe();
		bool process(int ac, char** av);
};

#endif