#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	else if (ac > 2) {
		std::cerr << "Error: too many arguments." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	if (btc.loadDataBase("data.csv"))
		btc.bitCoinCalculator(av[1]);
	else
		return 1;
	return 0;
}