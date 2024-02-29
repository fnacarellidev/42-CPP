#include "BitcoinExchange.hpp"

void	initializeBtcDb(BitcoinExchange &bitcoinExchange);
void	handleUserEntry(std::map<std::string, double> btcDb, std::string filename);

static bool	isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 !=  0) || (year % 400 == 0);
}

static bool	isUnsignedInteger(std::string str) {
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

static unsigned int countHyphens(std::string date) {
	unsigned int count = 0;

	for (std::string::iterator it = date.begin(); it != date.end(); ++it)
		if (*it == '-')
			++count;

	return count;
}

static void trimString(std::string &str) {
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

static std::map<int, int> getMonthsDaysMap(int year) {
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

static bool isDateFormatedAsExpected(std::string year, std::string month, std::string day) {
	for (std::string::iterator it = year.begin(); it != year.end(); ++it)
		if (!isdigit(static_cast<char>(*it))) return false;

	for (std::string::iterator it = month.begin(); it != month.end(); ++it)
		if (!isdigit(static_cast<char>(*it))) return false;

	for (std::string::iterator it = day.begin(); it != day.end(); ++it)
		if (!isdigit(static_cast<char>(*it))) return false;

	if (!(year.length() == 4 && month.length() == 2 && day.length() == 2)) {
		std::cout << "Error: Expected: YYYY-MM-DD\n";
		return false;
	}
	return true;
}

static bool isValidFile(std::string header) {
	std::string date;
	std::string value;
	std::string::size_type pos;

	pos = header.find('|');
	date = header.substr(0, pos);
	value = header.substr(++pos, header.length());
	trimString(date);
	trimString(value);
	return date == "date" && value == "value";
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

void	searchDb(std::map<std::string, double> btcDb, std::string dateToLookUp, double amountToBuy) {
	double	quotation;
	std::map<std::string, double>::iterator it = btcDb.lower_bound(dateToLookUp);

	if (it == btcDb.end())
		quotation = (--it)->second;
	else
	{
		if (it->first == dateToLookUp)
			quotation = it->second;
		else if (it == btcDb.begin())
			quotation = 0;
		else
			quotation = (--it)->second;
	}
	std::cout << dateToLookUp << " => " << amountToBuy << " = " << amountToBuy * quotation << std::endl;
}

bool validDate(std::string date) {
	size_t firstHyphenPos = date.find_first_of('-'); 
	size_t secondHyphenPos = date.find_last_of('-'); 
	std::string year = date.substr(0, firstHyphenPos).c_str();
	std::string month = date.substr(firstHyphenPos + 1, secondHyphenPos - firstHyphenPos - 1).c_str();
	std::string day = date.substr(secondHyphenPos + 1).c_str();
	int yearN = std::atoi(year.c_str());
	int monthN = std::atoi(month.c_str());
	int dayN = std::atoi(day.c_str());
	std::map<int, int> monthsDaysMap = getMonthsDaysMap(yearN);

	if (countHyphens(date) != 2) {
		std::cout << "Error: Expected YYYY-MM-DD\n";
		return false;
	}
	if (yearN < 1 || monthN < 1 || monthN > 12 || dayN < 1 || dayN > monthsDaysMap[monthN]) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	return isDateFormatedAsExpected(year, month, day);
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
		return;

	std::getline(file, line);

	if (!isValidFile(line))
		return;

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
