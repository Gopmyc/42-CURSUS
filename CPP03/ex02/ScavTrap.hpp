#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(const std::string& sName);
		~ScavTrap();

		void attack(const std::string& sTarget);
		void guardGate();
};

#endif
