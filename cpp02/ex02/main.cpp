#include "Fixed.hpp"
#include <iostream>

int main () {
	{
		std::cout << "TEST 0" << std::endl;
		Fixed	a;
		Fixed	b( Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 1" << std::endl;
		Fixed a(42);
		Fixed b(42);

		std::cout << a << " equal to " << b << "? : " << (a == b ? "true" : "false") << std::endl;
		std::cout << a << " different than " << b << "? : " << (a != b ? "true" : "false") << std::endl;
		std::cout << a << " bigger than " << b << "? : " << (a > b ? "true" : "false") << std::endl;
		std::cout << a << " less than " << b << "? : " << (a < b ? "true" : "false") << std::endl;
		std::cout << a << " bigger than or equal to " << b << "? : " << (a >= b ? "true" : "false") << std::endl;
		std::cout << a << " less than or equal to " << b << "? : " << (a <= b ? "true" : "false") << std::endl;
	}
	return (0);
}
