#include "Weapon.hpp"

Weapon::Weapon(const std::string& rsType) : sType(rsType) {}

const std::string& Weapon::getType() const {
	return sType;
}

void Weapon::setType(const std::string& rsNewType) {
	sType = rsNewType;
}
