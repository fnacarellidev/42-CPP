#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	std::string arg(argv[1]);

	if (arg.empty())
		return 1;
	try {
		RPN::calculate(arg);
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}
