#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <limits>

bool	isLeapYear(int year);
bool	isUnsignedInteger(std::string str);
unsigned int countHyphens(std::string date);
void	trimString(std::string &str);
std::map<int, int> getMonthsDaysMap(int year);
bool isDateFormatedAsExpected(std::string year, std::string month, std::string day);
bool isValidFile(std::string filename);

class BitcoinExchange {
	private:
		std::map<std::string, double> _btcDb;
	public:
		~BitcoinExchange();
		BitcoinExchange(char *filename);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange& copy);
		std::map<std::string, double> getBtcDb() const;
		void	setBtcDb(std::map<std::string, double> btcDb);
};
