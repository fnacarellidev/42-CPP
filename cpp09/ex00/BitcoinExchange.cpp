#include "BitcoinExchange.hpp"

void	initializeBtcDb(BitcoinExchange &bitcoinExchange);
void	handleUserEntry(std::map<std::string, double> btcDb, std::string filename);

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
	handleUserEntry(_btcDb, filename);
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

void	searchDb(std::map<std::string, double> btcDb, std::string dateToLookUp, double amountToBuy) {
	double	quotation;
	std::map<std::string, double>::iterator it = btcDb.lower_bound(dateToLookUp);

	if (it != btcDb.end())
		quotation = it->second;
	else
		quotation = (--it)->second;
	std::cout << dateToLookUp << " => " << amountToBuy << " = " << amountToBuy * quotation << std::endl;
}

bool validDate(std::string date) {
	size_t firstHyphenPos = date.find_first_of('-'); 
	size_t secondHyphenPos = date.find_last_of('-'); 
	int year = std::atoi(date.substr(0, firstHyphenPos).c_str());
	int month = std::atoi(date.substr(firstHyphenPos + 1, secondHyphenPos - firstHyphenPos - 1).c_str());
	int day = std::atoi(date.substr(secondHyphenPos + 1).c_str());
	std::map<int, int> monthsDaysMap = getMonthsDaysMap(year);

	if (countHyphens(date) != 2) {
		std::cout << "[DATEERR]: Expected YYYY-MM-DD; Got: " << date << std::endl;
		return false;
	}
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > monthsDaysMap[month]) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

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

void	handleUserEntry(std::map<std::string, double> btcDb, std::string filename) {
	std::string key;
	std::string line;
	std::string value;
	std::string::size_type pos;
	std::ifstream file(filename.c_str());
	std::map<std::string, double> userEntry;

	if (!file.good())
		exit(1);

	std::getline(file, line); // Skip first line
	while (file.good()) {
		std::getline(file, line);
		pos = line.find('|');
		key = line.substr(0, pos);
		value = line.substr(++pos, line.length());
		trimString(key);
		trimString(value);
		if (!line.empty() && validDate(key) && isUnsignedInteger(value))
			searchDb(btcDb, key, std::atof(value.c_str()));
	};
}
