#pragma once
# include <iostream>

class Prompt {
	private:
		static void			announceField(const char* field);
	public:
		static std::string	readFirstName(void);
		static std::string	readLastName(void);
		static std::string	readNickname(void);
		static std::string	readPhoneNumber(void);
		static std::string	readDarkestSecret(void);
		static void			printTemplate(std::string field);
		static void			printTemplate(int index);
		static int			readIndex(void);
};
