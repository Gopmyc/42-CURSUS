#pragma once

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string sName);
		~Zombie();
		
		void announce(void);
		void setName(std::string sName);

	private:
		std::string sName;
};

Zombie* zombieHorde( int N, std::string name );