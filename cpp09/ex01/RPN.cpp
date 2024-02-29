#include "RPN.hpp"
#include <sstream>

bool isOperator(std::string str) {
	return str == "+" || str == "-" || str == "*" || str == "/";
}

static bool isNumber(std::string str)
{
	std::string::iterator it = str.begin();

	if ((*it == '-' || *it == '+') && str.size() > 1)
		it++;
    while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

RPN::~RPN() { }

RPN::RPN() { }

RPN::RPN(const RPN& copy) {
	if (this != &copy)
		*this = copy;
}

RPN& RPN::operator=(const RPN& copy) {
	(void) copy;
	return *this;
}

int		getOperation(std::string op) {
	if (op == "+")
		return 1;
	else if (op == "-")
		return 2;
	else if (op == "*")
		return 3;
	else
		return 4;
}

void	runOperation(std::stack<int> &nums, std::string op) {
	int	x;
	int	y;

	y = nums.top();
	nums.pop();
	x = nums.top();
	nums.pop();
	switch (getOperation(op)) {
		case 1:
			nums.push(x + y);
			break;

		case 2:
			nums.push(x - y);
			break;

		case 3:
			nums.push(x * y);
			break;

		case 4:
			if (y == 0)
				throw std::runtime_error("Can't divide by zero");
			nums.push(x / y);
			break;

	}
}

void	RPN::calculate(std::string expression) {
	std::stack<int> nums;
	std::stringstream ss(expression);
	std::string param;

	while (ss >> param) {
		if (isNumber(param))
			nums.push(std::atoi(param.c_str()));
		else if (isOperator(param) && nums.size() > 1)
			runOperation(nums, param);
		else {
			std::cout << "Error\n";
			return ;
		}
	}
	nums.size() > 1 ? std::cout << "Error\n" : std::cout << nums.top() << std::endl;
}
