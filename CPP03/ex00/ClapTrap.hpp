#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	protected:
		std::string sName;
		unsigned int uHitPoints;
		unsigned int uEnergyPoints;
		unsigned int uAttackDamage;

	public:
		ClapTrap(const std::string& sName);
		~ClapTrap();

		void attack(const std::string& sTarget);
		void takeDamage(unsigned int uAmount);
		void beRepaired(unsigned int uAmount);
};

#endif
