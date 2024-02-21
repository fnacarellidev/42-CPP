#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>

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
