#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc < 2 && argv) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange exchange(argv[1]);
}
