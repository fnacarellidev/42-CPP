#pragma once
#include <iostream>
#include <limits>

class ScalarConverter
{
	public:
		~ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		static void	convert(std::string str);
		ScalarConverter &operator=(const ScalarConverter &copy);
};
