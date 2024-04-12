#include "./Weapon.hpp"
#include <cstddef>
#include <string>

Weapon::Weapon(): type("") {}
Weapon::Weapon(std::string str):type(str) {}

Weapon::~Weapon() {}

void	Weapon::setType(std::string str) {
	this->type = str;
}

const std::string& Weapon::getType() {
	return (type);
}