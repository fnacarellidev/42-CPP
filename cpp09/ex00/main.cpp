#include "BitcoinExchange.hpp"
#include <iomanip>

int main(int argc, char **argv) {
	std::map<std::string, double> a;
	if (argc < 2 && argv) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange exchange(argv[1]);
}
