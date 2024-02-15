#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { (void)obj; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

static bool	isPseudoLiteral(std::string str)
{
	std::string pseudoLiterals[] = {
		"inf",
		"+inf",
		"-inf",
		"inff",
		"+inff",
		"-inff",
		"nan",
		"nanf"
	};

	for (int i = 0; i < 8 ; i++)
		if (pseudoLiterals[i] == str) return (true);
	return (false);
}

static bool	isInt(std::string str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	return isdigit(str[i]);
}

static bool isChar(std::string str)
{
	return isascii(str[0]) && !isdigit(str[0]);
}

static bool	isFloat(std::string str)
{
	int	i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (isdigit(str[i]))
		i++;
	return str[i] == 'f' && isdigit(str[i - 1]);
}

static bool	isDouble(std::string str)
{
	int	i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	return str[i] == '.' && isdigit(str[i + 1]);
}
int	getDecimals(std::string str) {
	int	decimals = 0;
	int	dotIndex = str.find('.');

	if (dotIndex == -1) return 1;
	for (size_t i = dotIndex + 1; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			break ;
		decimals++;
	}
	return decimals;
}

static int	getType(std::string str)
{
	if (isPseudoLiteral(str))
		return 0;
	else if (isChar(str))
		return 1;
	else if (isFloat(str))
		return 2;
	else if (isDouble(str))
		return 3;
	else if (isInt(str))
		return 4;
	return -1;
}

static void	displayPseudoLiteral(std::string str) {
	std::cout << "char : impossible" << std::endl;

	if (str == "inf" || str == "+inf" || str == "-inf")
		std::cout << "int : " << str << std::endl;
	else
		std::cout << "int : impossible" << std::endl;

	if (str == "inf" || str == "+inf" || str == "-inf")
		std::cout << "float : " << str << "f" << std::endl;
	else
		std::cout << "float : " << str << "f" << std::endl;

	if (str == "inff" || str == "+inff" || str == "-inff")
		std::cout << "double : " << str.substr(0, str.size() - 1) << std::endl;
	else
		std::cout << "double : " << str << std::endl;
}

static void displayChar(std::string str) {
	int x = str[0];

	if (x < std::numeric_limits<char>::min() || x > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if (x >= 0 && x <= 32)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;

	std::cout << "int : " << static_cast<int>(x) << std::endl;
	std::cout << "float : " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(x) << ".0" << std::endl;
}

static void displayInt(std::string str) {
	double x = atof(str.c_str());

	if (x < std::numeric_limits<char>::min() || x > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if (x >= 0 && x <= 32)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;

	if (x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << x << std::endl;

	std::cout << "float : " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(x) << ".0" << std::endl;
}

static void displayDouble(std::string str) {
	double x = atof(str.c_str());
	int	xAsInt = x;
	int	precision = getDecimals(str);

	if (xAsInt < 0 || xAsInt < std::numeric_limits<char>::min() || xAsInt > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (xAsInt >= 0 && xAsInt <= 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(xAsInt) << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(xAsInt) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(precision) << static_cast<float>(x) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(precision) << static_cast<double>(x) << std::endl;
}

static void displayFloat(std::string str) {
	float x = atof(str.c_str());
	int xAsInt = x;
	int precision = getDecimals(str);

	if (xAsInt < 0 || xAsInt < std::numeric_limits<char>::min() || xAsInt > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (xAsInt >= 0 && xAsInt <= 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(xAsInt) << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(xAsInt) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(precision) << static_cast<float>(x) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(precision) << static_cast<double>(x) << std::endl;
}

void	ScalarConverter::convert(std::string str) {
	int	index = getType(str);
	void (*printers[])(std::string) = {
		displayPseudoLiteral,
		displayChar,
		displayFloat,
		displayDouble,
		displayInt
	};

	if (index == -1) {
		std::cout << "Invalid entry" << std::endl;
		return ;
	}
	printers[index](str);
}
