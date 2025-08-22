#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& sName) : sName(sName), uHitPoints(10), uEnergyPoints(10), uAttackDamage(0) {
	std::cout << "ClapTrap " << this->sName << " constructed" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->sName << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& sTarget) {
	if (!uHitPoints || !uEnergyPoints) {
		std::cout << "ClapTrap " << sName << " has no energy or hit points to attack" << std::endl;
		return;
	}
	uEnergyPoints--;
	std::cout << "ClapTrap " << sName << " attacks " << sTarget << ", causing " << uAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int uAmount) {
	if (!uHitPoints) {
		std::cout << "ClapTrap " << sName << " is already destroyed" << std::endl;
		return;
	}
	uHitPoints = (uAmount >= uHitPoints) ? 0 : uHitPoints - uAmount;
	std::cout << "ClapTrap " << sName << " takes " << uAmount << " points of damage, remaining HP: " << uHitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int uAmount) {
	if (!uHitPoints || !uEnergyPoints) {
		std::cout << "ClapTrap " << sName << " has no energy or hit points to repair" << std::endl;
		return;
	}
	uEnergyPoints--;
	uHitPoints += uAmount;
	std::cout << "ClapTrap " << sName << " repairs itself for " << uAmount << " hit points, total HP: " << uHitPoints << std::endl;
}
