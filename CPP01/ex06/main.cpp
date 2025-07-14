#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
		return 1;
	}

	Harl harl;
	Harl::LogLevel lvl = Harl::getLogLevel(argv[1]);
	harl.filter(lvl);

	return 0;
}
