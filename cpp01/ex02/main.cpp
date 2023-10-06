#include <iostream>

int main() {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	strPtr = &str;
	std::string&	strRef = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of strPtr: " << strPtr << std::endl;
	std::cout << "Address of strRef: " << &strRef << std::endl;

	std::cout << '\n';

	std::cout << "Content of str: " << str << std::endl;
	std::cout << "Content of strPtr: " << *strPtr << std::endl;
	std::cout << "Content of strRef: " << strRef << std::endl;
}
