#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int num) {
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw std::runtime_error("number not found!");
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int num) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw std::runtime_error("number not found!");
	return it;
}

#endif