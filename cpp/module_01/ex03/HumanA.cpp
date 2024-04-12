# include "./HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& wp): name(str), weapon(wp){}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}