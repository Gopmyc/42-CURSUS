#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string sName;

	public:
		DiamondTrap(const std::string& sName);
		~DiamondTrap();

		using ScavTrap::attack; // attaque = version ScavTrap
		void whoAmI();
};

#endif
