# include "./HumanB.hpp"

HumanB::HumanB(std::string str): name(str) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& wp) {
	weapon = &wp;
}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}