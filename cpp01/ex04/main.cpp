#include <fstream>
#include <ostream>
#include <iostream>
#include "StreamEditor.hpp"

bool	isValidFile(char* filename) {
	std::ifstream	ifs(filename);

	if (ifs.good())
		return true;
	return false;
}

int main(int argc, char **argv) {
	std::string		toSed;
	std::string		replaced;

	if (argc != 4) {
		std::cerr << "./sed file seekingString replace" << std::endl;
		return 1;
	}
	if (!isValidFile(argv[1]))
		return 1;
	toSed = StreamEditor::getIfsContent(argv[1]);
	replaced = StreamEditor::sed(toSed, argv[2], argv[3]);
	StreamEditor::saveToFile(argv[1], replaced);
	return (0);
}
