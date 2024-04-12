
#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string);
		Zombie();
		void announce(void);
		void setName(std::string name);
		~Zombie(void);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );

#endif