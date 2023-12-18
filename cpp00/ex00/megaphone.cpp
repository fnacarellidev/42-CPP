#include <iostream>

class Megaphone {
	public:
		static void scream(void) {
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		};
		static void scream(int argc, char **argv) {
			for (int i = 1; i < argc; ++i) {
				std::string arg = argv[i];
				for (size_t j = 0; j < arg.length(); ++j) {
					std::cout << char(toupper(arg[j]));
				}
			}
			std::cout << "\n";
		};
};

int main(int argc, char **argv) {
	argc < 2 ? Megaphone::scream() : Megaphone::scream(argc, argv);
	return 0;
}
