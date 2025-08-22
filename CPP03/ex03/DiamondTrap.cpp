#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& sName)
: ClapTrap(sName + "_clap_name"), FragTrap(sName), ScavTrap(sName), sName(sName) {
	uHitPoints = FragTrap::uHitPoints;       // 100
	uEnergyPoints = ScavTrap::uEnergyPoints; // 50
	uAttackDamage = FragTrap::uAttackDamage; // 30
	std::cout << "DiamondTrap " << this->sName << " constructed" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->sName << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->sName
	          << " | ClapTrap name: " << ClapTrap::sName << std::endl;
}
