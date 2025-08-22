#include "ClapTrap.hpp"

int main() {
	ClapTrap cA("Alpha");
	ClapTrap cB("Bravo");

	cA.attack("Bravo");
	cB.takeDamage(3);
	cB.beRepaired(2);
	cB.attack("Alpha");
	cA.takeDamage(5);
	cA.beRepaired(4);
}
