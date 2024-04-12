#include "./Zombie.hpp"


int main(void)
{
	Zombie *myNewZombie = newZombie("GINO");
	randomChump("LUCA");
	myNewZombie->announce();
	delete myNewZombie;
}