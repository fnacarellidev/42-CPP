#include "BitcoinExchange.hpp"

void	initializeBtcDb(BitcoinExchange &bitcoinExchange) {
	std::string key;
	std::string line;
	std::string::size_type pos;
	std::ifstream file("data.csv");
	std::map<std::string, double> btcDb;

	if (!file.good()) {
		std::cout << "Failed to read data.csv\n";
		exit(1);
	}

	do {
		std::getline(file, line);
		pos = line.find(',');
		key = line.substr(0, pos);
		btcDb[key] = std::atof(line.substr(++pos, line.length()).c_str());
	} while (file.good());

	bitcoinExchange.setBtcDb(btcDb);
}

bool	isUnsignedInteger(std::string str)
{
	size_t i = 0;

	if (str[i] == '-' || str.empty())
		return false;
	while (str[i] == '+' || isspace(str[i]))
		i++;
	while (isdigit(str[i])) {
		i++;
	}
	if (str[i] == '.')
		i++;
	while (isdigit(str[i]))
		i++;
	return i == str.length() ? true : false;
}

std::string trimString(std::string str) {
	std::string trimmedBegin(str.substr(0, str.find_last_not_of(" ") + 1));
	std::string trimmed(trimmedBegin.substr(0, str.find_first_of(" ")));

	return trimmed;
}

BitcoinExchange::~BitcoinExchange() {
#ifdef DEBUG
	std::cout << "[BITCOINEXCHANGE] Destructor called\n";
#endif
}

BitcoinExchange::BitcoinExchange(char* filename) {
#ifdef DEBUG
	std::cout << "[BITCOINEXCHANGE] Default constructor called\n";
#endif
	initializeBtcDb(*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
#ifdef DEBUG
	std::cout << "[BITCOINEXCHANGE] Copy constructor called\n";
#endif
	if (this != &copy)
		*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		_btcDb = copy.getBtcDb();
	}
	return *this;
}

std::map<std::string, double> BitcoinExchange::getBtcDb() const {
	return _btcDb;
}

void	BitcoinExchange::setBtcDb(std::map<std::string, double> btcDb) {
	_btcDb = btcDb;
}
