#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& rsName) : sName(rsName), pWeapon(0) {}

void HumanB::setWeapon(Weapon& rWeapon) {
	pWeapon = &rWeapon;
}

void HumanB::attack() const {
	if (pWeapon)
		std::cout << sName << " attacks with their " << pWeapon->getType() << std::endl;
	else
		std::cout << sName << " has no weapon to attack with" << std::endl;
}
