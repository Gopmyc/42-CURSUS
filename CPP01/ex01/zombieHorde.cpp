#include "Zombie.hpp"

Zombie* zombieHorde(int nCount, std::string sName)
{
	if (nCount <= 0)
		return NULL;

	Zombie* zpHorde = new Zombie[nCount];
	for (int i = 0; i < nCount; i++)
		zpHorde[i].setName(sName);

	return zpHorde;
}
