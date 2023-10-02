#pragma once
# include <iostream>

class Contacts {
	private:
		std::string lastName;
		std::string nickname;
		std::string firstName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getFirstName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
		void		setLastName(std::string lastName);
		void		setNickname(std::string lastName);
		void		setFirstName(std::string firstName);
		void		setPhoneNumber(std::string lastName);
		void		setDarkestSecret(std::string lastName);
};
