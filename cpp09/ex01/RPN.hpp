#pragma once
#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {
	private:
		~RPN();
		RPN();
		RPN(const RPN& copy);
		RPN &operator=(const RPN& copy);
	public:
		static void	calculate(std::string expression);
};
