#include "StreamEditor.hpp"
#include <fstream>

std::string StreamEditor::sed(std::string toSed, char* seek, char* replace) {
	std::string	replaced;
	std::string strToSeek(seek);

	for (size_t i = 0; i < toSed.length(); ++i) {
		std::string	possibleMatch = toSed.substr(i, strToSeek.length());
		if (possibleMatch == seek) {
			replaced += replace;
			i += strToSeek.length();
		}
		else
			replaced += toSed[i];
	}
	return replaced;
}

void		StreamEditor::saveToFile(char* filename, std::string replaced) {
	std::string		outfile = std::string(filename).append(".replace");
	std::ofstream	ofs(outfile.c_str());

	ofs.write(replaced.c_str(), replaced.length());
}

std::string	StreamEditor::getIfsContent(char *filename) {
	std::string		toSed;
	std::ifstream	ifs(filename);

	std::getline(ifs, toSed, '\0');
	return toSed;
}
