#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap cA("Alpha");
	ScavTrap sB("Bravo");

	cA.attack("Bravo");
	sB.attack("Alpha");

	cA.takeDamage(3);
	cA.beRepaired(2);

	sB.takeDamage(20);
	sB.beRepaired(10);
	sB.guardGate();
}
