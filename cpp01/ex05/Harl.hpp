#include <iostream>
#define DEBUG_MSG "[DEBUG] DEBUGGING"
#define INFO_MSG "[INFO] INFOS"
#define WARN_MSG "[WARNING] WARNINGS"
#define ERR_MSG "[ERROR] ERRORS"

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	complain(std::string level);
};
