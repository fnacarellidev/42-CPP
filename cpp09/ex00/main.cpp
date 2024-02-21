#include "BitcoinExchange.hpp"
#include <iomanip>

int main(int argc, char **argv) {
	if (argc < 2 && argv) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange exchange(argv[1]);
	std::map<std::string, double> userEntry = exchange.getUserEntry();
	std::cout << "User entry: \n";
	/* for (std::map<std::string, double>::iterator it = userEntry.begin(); it != userEntry.end(); ++it) { */
        /* std::cout << it->first << " => " << it->second << '\n'; */
    /* } */
}
