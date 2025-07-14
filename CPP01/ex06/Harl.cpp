#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	typedef void (Harl::*HarlMemFn)(void);
	struct LevelMap {
		std::string level;
		HarlMemFn func;
	};

	LevelMap levels[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};

	for (size_t i = 0; i < sizeof(levels) / sizeof(LevelMap); ++i) {
		if (levels[i].level == level) {
			(this->*levels[i].func)();
			return;
		}
	}
}

Harl::LogLevel Harl::getLogLevel(const std::string& levelStr) {
	if (levelStr == "DEBUG")
		return DEBUG;
	if (levelStr == "INFO")
		return INFO;
	if (levelStr == "WARNING")
		return WARNING;
	if (levelStr == "ERROR")
		return ERROR;
	return UNKNOWN;
}

void Harl::filter(LogLevel level) {
	switch (level) {
		case DEBUG:
			debug();
			/* fall through */
		case INFO:
			info();
			/* fall through */
		case WARNING:
			warning();
			/* fall through */
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
