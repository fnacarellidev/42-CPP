#include "Data.hpp"

Data::~Data() {
#ifdef DEBUG
	std::cout << "[DATA] Destructor called" << '\n';
#endif
}

Data::Data() {
#ifdef DEBUG
	std::cout << "[DATA] Default constructor called" << '\n';
#endif
}

Data::Data(int num) : x(num) {
#ifdef DEBUG
	std::cout << "[DATA] Parameter based constructor called" << '\n';
#endif
}

Data::Data(const Data& copy) {
#ifdef DEBUG
	std::cout << "[DATA] Copy constructor called" << '\n';
#endif
	if (this != &copy) *this = copy;
}

Data& Data::operator=(const Data& copy) {
	if (this != &copy) x = copy.x;
	return *this;
}
