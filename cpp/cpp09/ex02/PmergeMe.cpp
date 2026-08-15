#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	this->unsorted = copy.unsorted;
	this->_vec = copy._vec;
	this->_deq = copy._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		this->unsorted = copy.unsorted;
		this->_vec = copy._vec;
		this->_deq = copy._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string &strnum) {
	char *end = NULL;
	long num = std::strtol(strnum.c_str(), &end, 10);
	if (num < 0 || num > INT_MAX || *end != '\0') {
		std::cerr << "Error" << std::endl;
		return false;
	}
	this->_vec.push_back(static_cast<unsigned int>(num));
	this->_deq.push_back(static_cast<unsigned int>(num));
	return true;
}

bool PmergeMe::process(int ac, char **av) {
	std::string stringnum;
	for (int i = 1; i < ac; ++i) {
		std::istringstream iss(av[i]);
		while (iss >> stringnum) {
			if (!isValidNumber(stringnum))
				return false;
		}
	}
	return true;
}