# include "./Zombie.hpp"


void Zombie::announce()
{
	std::cout << this->name << ":" << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string zombie_name) : name(zombie_name){}
Zombie::Zombie(){}

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << std::endl;
}