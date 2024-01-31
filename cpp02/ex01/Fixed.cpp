#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int x) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = x * (1 << _fractionalBits);
}

Fixed::Fixed(const float x) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(x * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	return _rawBits;
}

Fixed	&Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_rawBits = copy.getRawBits();
	return (*this);
}

int		Fixed::toInt() const {
	return _rawBits / (1 << _fractionalBits);
}

float	Fixed::toFloat() const {
	return _rawBits / ((float) (1 << _fractionalBits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
