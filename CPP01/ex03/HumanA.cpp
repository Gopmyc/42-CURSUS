#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& rsName, Weapon& rWeapon) : sName(rsName), rWeapon(rWeapon) {}

void HumanA::attack() const {
	std::cout << sName << " attacks with their " << rWeapon.getType() << std::endl;
}
