#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dT("Diamond");

	dT.attack("Target");   // version ScavTrap
	dT.takeDamage(30);
	dT.beRepaired(20);
	dT.whoAmI();

	return 0;
}
