#include "Prompt.hpp"
#include <cstdlib>
#include <iomanip>
#include <string>

void		Prompt::announceField(const char* field) {
	std::cout << "Please write the " << field << " of the contact"<< std::endl;
}

std::string	Prompt::readField(const char* field) {
	std::string	fieldRead;

	do { 
		Prompt::announceField(field);
		if (!std::getline(std::cin, fieldRead))
			break ;
	}
	while (fieldRead.empty());
	return fieldRead;
}

int		Prompt::readIndex(void) {
	std::string	stringIndex;

	do {
		Prompt::announceField("index");
		if (!std::getline(std::cin, stringIndex))
			return -1;
	} while (stringIndex.empty() || !isdigit(stringIndex.at(0)));
	return std::atoi(stringIndex.c_str());
}

void	Prompt::printTemplate(std::string field) {
	std::string	croppedField = field.substr(0, 10);
	if (croppedField.length() == 10) {
		croppedField.erase(9, 1);
		croppedField.push_back('.');
	}
	std::cout << std::setw(10);
	std::cout << croppedField << "|";
}

void	Prompt::printTemplate(int index) {
	std::cout << std::setw(10);
	std::cout << index << "|";
}
