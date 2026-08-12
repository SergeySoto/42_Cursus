#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) {
	this->lifo = copy.lifo;
}

RPN& RPN::operator=(const RPN &copy) {
	if (this != &copy)
		this->lifo = copy.lifo;
	return *this;
}

RPN::~RPN() {}

void RPN::operation(const std::string &str) {
	for (unsigned int i = 0; i < str.length(); ++i) {
		char c = str[i];
		if (c == ' ') continue ;
		if (std::isdigit(c)) {
			this->lifo.push(c - '0');
			continue;
		}
		if (this->lifo.size() < 2){
			std::cerr << "Error" << std::endl;
			return;
		}
		int val2 = this->lifo.top(); this->lifo.pop();
		int val1 = this->lifo.top(); this->lifo.pop();
		switch (c) {
			case '+': (this->lifo.push(val1 + val2)); break;
			case '-': (this->lifo.push(val1 - val2)); break;
			case '*': (this->lifo.push(val1 * val2)); break;
			case '/': 
				if (val2 == 0) {
					std::cerr << "Error" << std::endl;
					return;
				}
				(this->lifo.push(val1 / val2)); break;
			default: std::cerr << "Error" << std::endl; return;
		}
	}
	if (this->lifo.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << this->lifo.top() << std::endl;
}