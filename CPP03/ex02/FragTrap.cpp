#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& sName) : ClapTrap(sName) {
	uHitPoints = 100;
	uEnergyPoints = 100;
	uAttackDamage = 30;
	std::cout << "FragTrap " << this->sName << " constructed" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->sName << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string& sTarget) {
	if (!uHitPoints || !uEnergyPoints) {
		std::cout << "FragTrap " << sName << " has no energy or hit points to attack" << std::endl;
		return;
	}
	uEnergyPoints--;
	std::cout << "FragTrap " << sName << " launches a powerful attack on " << sTarget
	          << ", causing " << uAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << sName << " requests a positive high five! ✋" << std::endl;
}
