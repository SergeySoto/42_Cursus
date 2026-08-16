#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	this->_vec = copy._vec;
	this->_deq = copy._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		this->_vec = copy._vec;
		this->_deq = copy._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::extractNumber(const std::string &strnum) {
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

void PmergeMe::printContainer(const std::vector<unsigned int> &container) {
	for (std::vector<unsigned int>::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

void PmergeMe::fordJohnson(std::vector<unsigned int> &container) {
	if (container.size() < 2)
		return ;
	std::vector<std::pair<unsigned int, unsigned int> > pairs_vector;
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		pairs_vector.push_back((container[i] > container[i + 1]) 
		? std::make_pair(container[i], container[i + 1]) 
		: std::make_pair(container[i + 1], container[i]));
	}
	bool hasOdd = (container.size() % 2 != 0);
	unsigned int oddVal = hasOdd ? container.back() : 0;
}

bool PmergeMe::process(int ac, char **av) {
	std::string stringnum;
	for (int i = 1; i < ac; ++i) {
		std::istringstream iss(av[i]);
		while (iss >> stringnum) {
			if (!extractNumber(stringnum))
				return false;
		}
	}
	std::cout << "Before: ";
	printContainer(this->_vec);
	std::clock_t start1 = std::clock();
	fordJohnson(this->_vec);
	std::clock_t end1 = std::clock();
	double time_vec = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000.0;

	return true;
}