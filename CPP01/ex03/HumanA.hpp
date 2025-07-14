#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	sName;
		Weapon&		rWeapon;

	public:
		HumanA(const std::string& rsName, Weapon& rWeapon);
		void attack() const;
};

#endif
