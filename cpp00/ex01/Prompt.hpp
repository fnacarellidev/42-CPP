#pragma once
# include <iostream>

class Prompt {
	private:
		static void			announceField(const char* field);
	public:
		static std::string	readField(const char* field);
		static void			printTemplate(std::string field);
		static void			printTemplate(int index);
		static int			readIndex(void);
};
