#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class HumanB {
	std::string name;
	Weapon*		weapon;
	public:
		HumanB(std::string);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon&);
};

#endif