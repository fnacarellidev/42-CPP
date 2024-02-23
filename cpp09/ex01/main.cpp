#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	std::string arg(argv[1]);

	if (arg.empty())
		return 1;
	RPN::calculate(arg);
}
