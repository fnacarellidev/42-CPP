#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &obj)
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

bool Fixed::operator<(const Fixed &fixed) {
	return getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>(const Fixed &fixed) {
	return getRawBits() > fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) {
	return getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) {
	return getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) {
	return getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) {
	return getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) {
	return (toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
	return (toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) {
	return (toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
	return (toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed backup = *this;
	_rawBits++;
	return backup;
}

Fixed &Fixed::operator--() {
	_rawBits++;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed backup = *this;
	_rawBits++;
	return backup;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a >= b)
		return b;
	return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return max(Fixed(a), Fixed(b));
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return min(Fixed(a), Fixed(b));
}
