#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string	sType;

	public:
		Weapon(const std::string& rsType);
		const std::string& getType() const;
		void setType(const std::string& rsNewType);
};

#endif