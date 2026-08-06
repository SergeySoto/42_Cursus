#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
#include <iterator>
#include <iostream>


class Span {
	private:
		unsigned int N;
		std::vector<int> _vector;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();
		void addNumber(int value);
		int shortestSpan();
		int longestSpan();

		template <typename T>
		void addRange(T begin, T end) {
			if ((this->N - this->_vector.size()) < static_cast<unsigned int>(std::distance(begin, end)))
				throw std::out_of_range("Out of range");
			this->_vector.insert(_vector.end(), begin, end);
		}

		class ArrayTooShort : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif