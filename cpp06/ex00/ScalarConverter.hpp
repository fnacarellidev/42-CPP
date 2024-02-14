#pragma once
#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		~ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		static void	convert(std::string str);
};
