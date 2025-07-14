#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	sName;
		Weapon*		pWeapon;

	public:
		HumanB(const std::string& rsName);
		void setWeapon(Weapon& rWeapon);
		void attack() const;
};

#endif
