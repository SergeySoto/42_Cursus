#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <cctype>

class RPN {
	private:
		std::stack<int> lifo;
	public:
		RPN();
		RPN(const RPN &copy);
		RPN& operator=(const RPN &copy);
		~RPN();
		void operation(const std::string &str);
};

#endif