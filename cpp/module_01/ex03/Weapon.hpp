#ifndef WEAPON_H
#define WEAPON_H

#include "iostream"

class Weapon{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string);

		void setType(std::string var);
		const std::string& getType();
		
		~Weapon();
};

#endif