#include "Fixed.hpp"

Fixed::Fixed(const int x) {

}

Fixed::Fixed(const float x){
	_rawBits = round(x * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor operator called" << std::endl;
}
