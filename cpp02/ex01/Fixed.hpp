#pragma once
#include <iostream>
#include <math.h>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int x);
		Fixed(const float x);
		Fixed(Fixed const &copy);
		~Fixed();
		Fixed & operator = (const Fixed &copy);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
		friend	std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
};
