#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>

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
		if (pseudoLiterals[i] == str)	
			return (true);
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

static int	getType(std::string str)
{
	if (isPseudoLiteral(str))
		return (0);
	else if (isChar(str))
		return (1);
	else if (isInt(str))
		return (2);
	else if (isFloat(str))
		return (3);
	else if (isDouble(str))
		return (4);
	else
		return(-1);
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
		std::cout << "float : " << str << std::endl;

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
		std::cout << "'" << static_cast<char>(x) << "'" << std::endl;

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
		std::cout << "'" << static_cast<char>(x) << "'" << std::endl;

	if (x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << x << std::endl;

	std::cout << "float : " << static_cast<int>(x) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<int>(x) << ".0" << std::endl;
}

void	ScalarConverter::convert(std::string str) {
	int	index = getType(str);
	void (*printers[])(std::string) = { displayPseudoLiteral, displayChar, displayInt };

	if (index == -1) {
		std::cout << "Invalid entry" << std::endl;
		return ;
	}
	printers[index](str);
}
