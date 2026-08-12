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
	std::string list = "+-/*";
	for (int c = 0; c != '\0'; ++c) {
		if (c == ' ')
			continue ;
		if (std::isdigit(c)) //int num = c - '0';
			this->lifo.push(c);
		if (list.find(c) != std::string::npos) {
			int val2 = this->lifo.top(); this->lifo.pop(); //switch?? think about it!
			int val1 = this->lifo.top(); this->lifo.pop();
		}
	}
}