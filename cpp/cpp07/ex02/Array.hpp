#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <ctime>
#include <cstdlib>

template <typename T> class Array {
	private:
		T *_arr;
		unsigned int _size;
	public:
		Array() : _arr(new T[0]()), _size(0) {}
		Array(const Array& copy) {
			this->_size = copy._size;
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; ++i)
				this->_arr[i] = copy._arr[i];
		}
		Array(unsigned int n) : _arr(new T[n]()), _size(n) {}
		Array& operator=(const Array& copy) {
			if (this != &copy) {
				delete[] this->_arr;
				this->_size = copy._size;
				this->_arr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; ++i)
					this->_arr[i] = copy._arr[i];
			}
			return *this;
		}
		~Array() {
			delete[] _arr;
		}
		unsigned int size() const {
			return _size;
		}
		const T& operator[] (unsigned int index) const {
			if (index >= this->_size) {
				throw std::out_of_range("Index out of range");
			}
			return _arr[index];
		}
		T& operator[] (unsigned int index) {
			if (index >= this->_size) {
				throw std::out_of_range("Index out of range");
			}
			return _arr[index];
		}
};

#endif