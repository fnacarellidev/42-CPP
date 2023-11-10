#pragma once
#include <iostream>
#include <math.h>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	public:
		Fixed(const int x);
		Fixed(const float x);
		~Fixed();
		Fixed & operator = (const Fixed &rhs);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};
