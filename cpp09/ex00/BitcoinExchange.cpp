#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>
#include <limits>

bool	isUnsignedInteger(std::string str)
{
	size_t i = 0;
	long int num;
	std::stringstream ss(str);

	ss >> num;
	if (ss && num > std::numeric_limits<int>::max()) {
		std::cout << "Error: Too large a number.\n";
		return false;
	}
	if (str[i] == '-' || str.empty()) {
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	while (str[i] == '+' || isspace(str[i]))
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (isdigit(str[i]))
		i++;
	return i == str.length() ? true : false;
}

unsigned int countHyphens(std::string date) {
	unsigned int count;

	for (std::string::iterator it = date.begin(); it != date.end(); ++it)
		if (*it == '-')
			++count;

	return count;
}

void trimString(std::string &str) {
    std::string::iterator it = str.begin();

    if (str.empty()) return;
    while (it != str.end() && isspace(*it))
        ++it;
    str.erase(str.begin(), it);
    it = str.end();
    do
		--it;
    while (it != str.begin() && isspace(*it));
    str.erase(it +  1, str.end());
}

bool isLeapYear(int year) { return (year % 4 == 0 && year % 100 !=  0) || (year % 400 == 0); }

std::map<int, int> getMonthsDaysMap(int year) {
	std::map<int, int> monthsDaysMap;

	for (int i = 1; i < 13; ++i) {
		if (i == 2)
			monthsDaysMap[i] = isLeapYear(year) ? 29 : 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			monthsDaysMap[i] = 30;
		else
			monthsDaysMap[i] = 31;
	}

	return monthsDaysMap;
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

void	searchDb(std::map<std::string, double> btcDb, std::string dateToLookUp, double amountToBuy) {
	std::map<std::string, double>::iterator it = btcDb.begin();

	if (btcDb.find(dateToLookUp) != btcDb.end()) {
		std::cout << dateToLookUp << " => " << amountToBuy << " = " << btcDb[dateToLookUp] * amountToBuy << std::endl;
	}
	else
	{
		btcDb[dateToLookUp] = 0;
		it = btcDb.find(dateToLookUp);
		it--;
		std::cout << dateToLookUp << " => " << amountToBuy << " = " << it->second * amountToBuy << std::endl;
		btcDb.erase(dateToLookUp);
	}
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
