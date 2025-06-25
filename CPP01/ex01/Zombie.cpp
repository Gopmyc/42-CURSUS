#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string sName)
{
	this->sName = sName;
}

Zombie::~Zombie()
{
	std::cout << this->sName << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->sName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string sName)
{
	this->sName = sName;
}
