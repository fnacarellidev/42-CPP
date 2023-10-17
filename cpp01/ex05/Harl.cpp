#include "Harl.hpp"

void	Harl::debug(void) { std::cout << DEBUG_MSG << std::endl; }
void	Harl::info(void) { std::cout << INFO_MSG << std::endl; }
void	Harl::warning(void) { std::cout << WARN_MSG << std::endl; }
void	Harl::error(void) { std::cout << ERR_MSG << std::endl; }

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*funcPtrs[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (size_t i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			(this ->* funcPtrs[i])();
		}
	}
}
