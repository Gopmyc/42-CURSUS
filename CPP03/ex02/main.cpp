#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap cA("Alpha");
	ScavTrap sB("Bravo");
	FragTrap fC("Charlie");

	cA.attack("Bravo");
	sB.attack("Alpha");
	fC.attack("Bravo");

	cA.takeDamage(5);
	cA.beRepaired(3);

	sB.takeDamage(15);
	sB.beRepaired(5);
	sB.guardGate();

	fC.takeDamage(40);
	fC.beRepaired(20);
	fC.highFivesGuys();
}
