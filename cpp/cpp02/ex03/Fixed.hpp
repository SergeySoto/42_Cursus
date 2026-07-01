#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
			int _fixP;
			static const int _numBit = 8;
	public:
			Fixed();
			Fixed(const Fixed& copy);
			Fixed(const int num);
			Fixed(const float num);
			Fixed& operator=(const Fixed& copy);
			~Fixed();
			int getRawBits() const;
			void setRawBits(int const raw);
			int toInt() const;
			float toFloat() const;
			bool operator>(const Fixed& other) const;
			bool operator<(const Fixed& other) const;
			bool operator>=(const Fixed& other) const;
			bool operator<=(const Fixed& other) const;
			bool operator==(const Fixed& other) const;
			bool operator!=(const Fixed& other) const;
			Fixed operator+(const Fixed& other) const;
			Fixed operator-(const Fixed& other) const;
			Fixed operator*(const Fixed& other) const;
			Fixed operator/(const Fixed& other) const;
			Fixed& operator++();
			Fixed operator++(int);
			Fixed& operator--();
			Fixed operator--(int);
			static Fixed& min(Fixed& a, Fixed& b);
			static const Fixed& min(const Fixed& a, const Fixed& b);
			static Fixed& max(Fixed& a, Fixed& b);
			static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);


#endif