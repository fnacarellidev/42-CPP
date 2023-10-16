#include <iostream>

class StreamEditor {
	public:
		static std::string	sed(std::string toSed, char* seek, char* replace);
		static void			saveToFile(char* filename, std::string replaced);
		static std::string	getIfsContent(char* filename);
};
