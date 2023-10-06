#include "Prompt.hpp"
#include <cstdlib>
#include <iomanip>
#include <string>

void		Prompt::announceField(const char* field) {
	std::cout << "Please write the " << field << " of the contact"<< std::endl;
}

std::string	Prompt::readFirstName(void) {
	std::string	firstName;

	do { 
		Prompt::announceField("first name");
		if (!std::getline(std::cin, firstName))
			break ;
	}
	while (firstName.empty());
	return firstName;
}

std::string	Prompt::readLastName(void) {
	std::string	lastName;

	do {
		Prompt::announceField("last name");
		if (!std::getline(std::cin, lastName))
			break ;
	}
	while (lastName.empty());
	return lastName;
}

std::string	Prompt::readNickname(void) {
	std::string	nickname;

	do {
		Prompt::announceField("nickname");
		if (!std::getline(std::cin, nickname))
			break ;
	}
	while (nickname.empty());
	return nickname;
}

std::string	Prompt::readPhoneNumber(void) {
	std::string	phoneNumber;

	do {
		Prompt::announceField("phone number");
		if (!std::getline(std::cin, phoneNumber))
			break ;
	}
	while (phoneNumber.empty());
	return phoneNumber;
}

std::string	Prompt::readDarkestSecret(void) {
	std::string	darkestSecret;

	do {
		Prompt::announceField("darkest secret");
		if (!std::getline(std::cin, darkestSecret))
			break ;
	}
	while (darkestSecret.empty());
	return darkestSecret;
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
