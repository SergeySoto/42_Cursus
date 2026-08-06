#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void printT(T &c) {
	std::cout << c << std::endl;
}

template <typename T>
void plusOne(T &c) {
	c += 1;
}

template <typename T, typename Func>
void iter(T *array, size_t len, Func f) {
	for (size_t i = 0; i < len; i++)
		f (array[i]);
}

#endif