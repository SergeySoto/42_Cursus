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

/**
 * fordJhonson(std::vector<unsigned int> vec) {
 * 	std::vector<std::pair<int, int>>	new;
 * 	std::vector<int>					ganadores;
 * 	std::vector<int>					perdedores;
 * 	int									oddVal = -1;
 * 
 * 	if (vec.size < 2)
 * 		return (vec);
 * 	new = newVecPair(vec, oddVal);
 * 	
 * 	//Separas new en dos std::vector<int> | Ganadores y Perdedores
 * 	divideVecPair(new, ganadores, perdedores);
 * 	
 * 	//A los ganadores le agregas el primero de los perdedores
 * 	ganadores.pushback(perdedores[0]);
 * 	perdedores.pop();
 * 	
 * 	//A los perdedores le agregas el oddVal si existe;
 * 	ganadores = fordJhonson(ganadores);
 * 	if (oddVal > -1)
 * 		perdedores.pushback(oddVal);
 * 	
 * 	//perdedores insercion binaria ganadores
 * 	std::lower_bound(???);
 * 	return (ganadoers);
 * }
 */

//std::vector<std::pair<int, int> PmergeMe::newVecPair(std::vector<unsigned int> &container, int &oddVal)

std::vector<std::pair<unsigned int, unsigned int> > PmergeMe::newVecPair(std::vector<unsigned int> &container) {
	std::vector<std::pair<unsigned int, unsigned int> > pairs_vector;
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		pairs_vector.push_back((container[i] > container[i + 1]) 
		? std::make_pair(container[i], container[i + 1]) 
		: std::make_pair(container[i + 1], container[i]));
	}
	return pairs_vector;
}

void PmergeMe::fordJohnson(std::vector<unsigned int> &container) {
	if (container.size() < 2)
		return ;
	bool hasOdd = (container.size() % 2 != 0);
	unsigned int oddVal = hasOdd ? container.back() : 0;
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
	if (!pend.empty())
		winners.insert(winners.begin(), pend[0]);
	std::vector<unsigned int>::iterator it;
	if (hasOdd) {
		it = std::lower_bound(winners.begin(), winners.end(), oddVal);
		winners.insert(it, oddVal);
	}
	int last_jacob = 1;
	int current_jacob = 3;
	while (last_jacob < pend.size()) {
		
	}
	container = winners;
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