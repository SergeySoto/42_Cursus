#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& copy) : N(copy.N), _vector(copy._vector) {}

Span& Span::operator=(const Span& copy) {
	if (this != &copy) {
		this->_vector = copy._vector;
		this->N = copy.N;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (this->_vector.size() < this->N)
		this->_vector.push_back(value);
	else
		throw std::out_of_range("Out of range");
}

int Span::shortestSpan() {
	if (_vector.size() < 2)
		throw Span::ArrayTooShort();
	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	int min_span = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < tmp.size() - 1; ++i) {
		int current_span = tmp[i + 1] - tmp[i];
		if (current_span < min_span)
			min_span = current_span;
	}
	return min_span;
}

int Span::longestSpan() {
	if (_vector.size() < 2)
		throw Span::ArrayTooShort();
	return  *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());
}

const char* Span::ArrayTooShort::what() const throw() {
	return "Array too short to find the span.";
}