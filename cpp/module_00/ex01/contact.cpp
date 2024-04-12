#include "./contact.hpp"

Contact::Contact(std::string name, std::string surname, std::string phone_number, std::string nickname, std::string secret) {
	this->name = name;
	this->surname = surname;
	this->phone_number = phone_number;
	this->nickname = nickname;
	this->secret = secret;
}

Contact::Contact() {}

std::string Contact::get_secret() {
	return (this->secret);
}

void Contact::print_short() {
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << name.substr(0, 9) + (name.length() > 9 ? "." : "");
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << surname.substr(0, 9) + (surname.length() > 9 ? "." : " ");
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << nickname.substr(0, 9) + (nickname.length() > 9 ? "." : " ");
	std::cout << "|" << std::endl;
}

void Contact::print() {
	std::cout << "First Name: " << name
	<< "\nLast Name: " << surname
	<< "\nNickname: " << nickname
	<< "\nPhone Number: " << phone_number
	<< "\nDarkest Secret: " << secret
	<< std::endl;
}
