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
	std::vector<unsigned int>::const_iterator it = container.begin();
	int count = 0;
	for (; it != container.end() && count < 10; ++it, ++count)
		std::cout << *it << " ";
	if (container.size() > 10)
		std::cout << "[...]";
	std::cout << "\n";
}

void PmergeMe::printContainer(const std::deque<unsigned int> &container) {
	std::deque<unsigned int>::const_iterator it = container.begin();
	int count = 0;
	for (; it != container.end() && count < 10; ++it, ++count)
		std::cout << *it << " ";
	if (container.size() > 10)
		std::cout << "[...]";
	std::cout << "\n";
}

std::vector<std::pair<unsigned int, unsigned int> > PmergeMe::newVecPair(std::vector<unsigned int> &container) {
	std::vector<std::pair<unsigned int, unsigned int> > pairs_vector;
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		pairs_vector.push_back((container[i] > container[i + 1]) 
		? std::make_pair(container[i], container[i + 1]) 
		: std::make_pair(container[i + 1], container[i]));
	}
	return pairs_vector;
}

std::deque<std::pair<unsigned int, unsigned int> > PmergeMe::newVecPair(std::deque<unsigned int> &container) {
	std::deque<std::pair<unsigned int, unsigned int> > pairs_vector;
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		pairs_vector.push_back((container[i] > container[i + 1]) 
		? std::make_pair(container[i], container[i + 1]) 
		: std::make_pair(container[i + 1], container[i]));
	}
	return pairs_vector;
}

std::vector<size_t> PmergeMe::generateJacob(size_t limit, std::vector<unsigned int> &container) {
	(void)container;
	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < limit) {
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

std::deque<size_t> PmergeMe::generateJacob(size_t limit, std::deque<unsigned int> &container) {
	(void)container;
	std::deque<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < limit) {
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

std::vector<unsigned int> PmergeMe::jacobsthal(std::vector<unsigned int> &winners, std::vector<unsigned int> &pend,
	bool &hasOdd, unsigned int &oddVal) {
	std::vector<unsigned int> original_winners = winners;
	if (!pend.empty())
		winners.insert(winners.begin(), pend[0]);
	std::vector<size_t> jacob = generateJacob(pend.size(), winners);
	size_t last_jacob = 1;
	for (size_t i = 3; i < jacob.size(); ++i) {
		size_t current_jacob = jacob[i];
		if (current_jacob > pend.size())
			current_jacob = pend.size();
		for (size_t j = current_jacob - 1; j >= last_jacob; --j) {
			std::vector<unsigned int>::iterator it;
			std::vector<unsigned int>::iterator iterador_busqueda = std::find(winners.begin(), winners.end(), original_winners[j]);
			it = std::lower_bound(winners.begin(), iterador_busqueda, pend[j]);
			winners.insert(it, pend[j]);
		}
		last_jacob = current_jacob;
	}
	if (hasOdd) {
		std::vector<unsigned int>::iterator it;
		it = std::lower_bound(winners.begin(), winners.end(), oddVal);
		winners.insert(it, oddVal);
	}
	return winners;
}

std::deque<unsigned int> PmergeMe::jacobsthal(std::deque<unsigned int> &winners, std::deque<unsigned int> &pend,
	bool &hasOdd, unsigned int &oddVal) {
	std::deque<unsigned int> original_winners = winners;
	if (!pend.empty())
		winners.insert(winners.begin(), pend[0]);
	std::deque<size_t> jacob = generateJacob(pend.size(), winners);
	size_t last_jacob = 1;
	for (size_t i = 3; i < jacob.size(); ++i) {
		size_t current_jacob = jacob[i];
		if (current_jacob > pend.size())
			current_jacob = pend.size();
		for (size_t j = current_jacob - 1; j >= last_jacob; --j) {
			std::deque<unsigned int>::iterator it;
			std::deque<unsigned int>::iterator iterador_busqueda = std::find(winners.begin(), winners.end(), original_winners[j]);
			it = std::lower_bound(winners.begin(), iterador_busqueda, pend[j]);
			winners.insert(it, pend[j]);
		}
		last_jacob = current_jacob;
	}
	if (hasOdd) {
		std::deque<unsigned int>::iterator it;
		it = std::lower_bound(winners.begin(), winners.end(), oddVal);
		winners.insert(it, oddVal);
	}
	return winners;
}

void PmergeMe::fordJohnson(std::vector<unsigned int> &container) {
	if (container.size() < 2)
		return ;
	bool hasOdd = (container.size() % 2 != 0);
	unsigned int oddVal = hasOdd ? container.back() : 0;
	(void)oddVal;
	std::vector<std::pair<unsigned int, unsigned int> > pairs_vector = newVecPair(container);
	std::vector<unsigned int> winners;
	for (size_t i = 0; i < pairs_vector.size(); ++i) {
		winners.push_back(pairs_vector[i].first);
	}
	fordJohnson(winners);
	std::vector<unsigned int> pend;
	for (size_t i = 0; i < winners.size(); ++i) {
		for (size_t j = 0; j < pairs_vector.size(); ++j) {
			if (winners[i] == pairs_vector[j].first) {
				pend.push_back(pairs_vector[j].second);
				break ;
			}
		}
	}
	container = jacobsthal(winners, pend, hasOdd, oddVal);
}

void PmergeMe::fordJohnson(std::deque<unsigned int> &container) {
	if (container.size() < 2)
		return ;
	bool hasOdd = (container.size() % 2 != 0);
	unsigned int oddVal = hasOdd ? container.back() : 0;
	(void)oddVal;
	std::deque<std::pair<unsigned int, unsigned int> > pairs_vector = newVecPair(container);
	std::deque<unsigned int> winners;
	for (size_t i = 0; i < pairs_vector.size(); ++i) {
		winners.push_back(pairs_vector[i].first);
	}
	fordJohnson(winners);
	std::deque<unsigned int> pend;
	for (size_t i = 0; i < winners.size(); ++i) {
		for (size_t j = 0; j < pairs_vector.size(); ++j) {
			if (winners[i] == pairs_vector[j].first) {
				pend.push_back(pairs_vector[j].second);
				break ;
			}
		}
	}
	container = jacobsthal(winners, pend, hasOdd, oddVal);
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
	std::cout << "Before: " << std::setw(3);
	printContainer(this->_vec);
	//std::cout << "Deque Before: " << std::setw(4);
	//printContainer(this->_deq);
	std::clock_t start1 = std::clock();
	fordJohnson(this->_vec);
	std::clock_t end1 = std::clock();
	std::clock_t start2 = std::clock();
	fordJohnson(this->_deq);
	std::clock_t end2 = std::clock();
	std::cout << "After: " << std::setw(4);
	printContainer(this->_vec);
	//std::cout << "Deque After: " << std::setw(4);
	//printContainer(this->_deq);
	double time_vec = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_vec.size() 
		<< " elements with std::vector : " 
		<< std::fixed << std::setprecision(5) << std::setw(7) << time_vec << " us" << std::endl;
	double time_deq = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->_deq.size() 
		<< " elements with std::deque : " 
		<< std::fixed << std::setprecision(5) << std::setw(8) << time_deq << " us" << std::endl;
	return true;
}