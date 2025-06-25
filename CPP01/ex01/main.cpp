#include "Zombie.hpp"


int main(void)
{
	int nSize = 10;
	Zombie* zpHorde = zombieHorde(nSize, "Hordeur");

	for (int i = 0; i < nSize; i++)
		zpHorde[i].announce();

	delete[] zpHorde;

	return 0;
}