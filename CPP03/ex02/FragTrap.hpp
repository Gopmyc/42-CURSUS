#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string& sName);
		~FragTrap();

		void attack(const std::string& sTarget);
		void highFivesGuys(void);
};

#endif
