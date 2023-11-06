#pragma once
#include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed & operator = (const Fixed &rhs);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};
