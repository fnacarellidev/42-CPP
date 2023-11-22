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
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	& operator = (const Fixed &copy);
		bool	operator < (const Fixed &fixed);
		bool	operator > (const Fixed &fixed);
		bool	operator >= (const Fixed &fixed);
		bool	operator <= (const Fixed &fixed);
		bool	operator == (const Fixed &fixed);
		bool	operator != (const Fixed &fixed);
		Fixed	operator + (const Fixed &fixed);
		Fixed	operator - (const Fixed &fixed);
		Fixed	operator / (const Fixed &fixed);
		Fixed	operator * (const Fixed &fixed);
		Fixed	operator ++ (int);
		Fixed	operator -- (int);
		Fixed	& operator ++ ();
		Fixed	& operator -- ();
		static	Fixed	&min(Fixed &a, Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	Fixed	&min(const Fixed &a, const Fixed &b);
		static	Fixed	&max(const Fixed &a, const Fixed &b);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
		friend	std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
};
