#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& sName) : ClapTrap(sName) {
	uHitPoints = 100;
	uEnergyPoints = 50;
	uAttackDamage = 20;
	std::cout << "ScavTrap " << this->sName << " constructed" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->sName << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& sTarget) {
	if (!uHitPoints || !uEnergyPoints) {
		std::cout << "ScavTrap " << sName << " has no energy or hit points to attack" << std::endl;
		return;
	}
	uEnergyPoints--;
	std::cout << "ScavTrap " << sName << " ferociously attacks " << sTarget << ", causing " << uAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << sName << " is now in Gate Keeper mode" << std::endl;
}
