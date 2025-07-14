#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	public:
		enum LogLevel {
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			UNKNOWN
		};

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		void complain(std::string level);
		void filter(LogLevel level);

		static LogLevel getLogLevel(const std::string& levelStr);
};

#endif
