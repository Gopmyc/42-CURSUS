#include "Zombie.hpp"

Zombie* newZombie(std::string sName)
{
	return new Zombie(sName);
}
