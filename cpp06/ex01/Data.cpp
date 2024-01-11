#include "Data.hpp"

Data::~Data() {
	std::cout << "[DATA] Destructor called" << '\n';
}

Data::Data() {
	std::cout << "[DATA] Default constructor called" << '\n';
}

Data::Data(int num) : x(num) {
	std::cout << "[DATA] Parameter based constructor called" << '\n';
}

Data::Data(const Data& copy) {
	std::cout << "[DATA] Copy constructor called" << '\n';
	if (this != &copy) *this = copy;
}

Data& Data::operator=(const Data& copy) {
	if (this != &copy) x = copy.x;
	return *this;
}
