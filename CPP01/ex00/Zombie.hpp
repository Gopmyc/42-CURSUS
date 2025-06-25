#pragma once

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(std::string sName);
		~Zombie();
		void announce(void);

	private:
		std::string sName;
};

Zombie* newZombie(std::string sName);
void randomChump(std::string sName);