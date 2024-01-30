#include <iostream>

int main() {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << '\n';

	std::cout << "Content of str: " << str << std::endl;
	std::cout << "Content of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Content of stringREF: " << stringREF << std::endl;
}
