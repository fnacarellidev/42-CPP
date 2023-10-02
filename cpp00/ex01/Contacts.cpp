#include "Contacts.hpp"

void Contacts::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contacts::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contacts::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void Contacts::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contacts::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contacts::getFirstName(void) {
	return this->firstName;
}

std::string Contacts::getLastName(void) {
	return this->lastName;
}

std::string Contacts::getNickname(void) {
	return this->nickname;
}

std::string Contacts::getPhoneNumber(void) {
	return this->phoneNumber;
}

std::string Contacts::getDarkestSecret(void) {
	return this->darkestSecret;
}
