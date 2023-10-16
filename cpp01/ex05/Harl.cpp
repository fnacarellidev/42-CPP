#include "Harl.hpp"

void	Harl::debug(void) { std::cout << DEBUG_MSG << std::endl; }
void	Harl::info(void) { std::cout << INFO_MSG << std::endl; }
void	Harl::warning(void) { std::cout << WARN_MSG << std::endl; }
void	Harl::error(void) { std::cout << ERR_MSG << std::endl; }

void	Harl::complain(std::string level) {
	int			idx = -1;
	const char *levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			idx = i;
			break ;
		}
	}
	if (idx != -1) { (this->*funcPtrs[idx])(); }
	else { std::cout << "out" << std::endl; }
}

Harl::Harl() {
	this->funcPtrs[0] = &Harl::debug;
	this->funcPtrs[1] = &Harl::info;
	this->funcPtrs[2] = &Harl::warning;
	this->funcPtrs[3] = &Harl::error;
}
