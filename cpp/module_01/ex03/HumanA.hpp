#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"

class HumanA {
	std::string name;
	Weapon&		weapon;
	public:
		HumanA(std::string, Weapon&);
		~HumanA();
		void	attack();
};

#endif