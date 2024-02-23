#include "BitcoinExchange.hpp"

bool	isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 !=  0) || (year % 400 == 0);
}

bool	isUnsignedInteger(std::string str) {
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

bool isDateFormatedAsExpected(std::string year, std::string month, std::string day) {
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

bool isValidFile(std::string header) {
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
