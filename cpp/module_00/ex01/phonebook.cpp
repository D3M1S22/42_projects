#include "./phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook() {
	this->contact_count = 0;
	this->over_count = 1;
}


int PhoneBook::add_contact()
{
	if(this->contact_count == 8)
	{
		std::cout << "Phonebook is full replacing the oldest" << std::endl;
		this->over_count = 0;
	}
	std::string name;
	std::string surname;
	std::string phone_number;
	std::string nickname;
	std::string secret;

	std::cin.ignore();
	check_input(&name, "Name");
	check_input(&surname, "Surname");
	check_input(&phone_number, "Phone number");
	check_input(&nickname, "Nickname");
	check_input(&secret, "Secret");
	this->contacts[this->contact_count % 8] =  Contact(name, surname, phone_number, nickname, secret);
	this->contact_count++;
	return (0);
}

void PhoneBook::print()
{
	int i = this->over_count ? 0 : (this->contact_count % 8);
	int j = i == 0 ? -99 : i - 1;
	int resetted = 0;
	std::cout << "**********************************************" << std::endl;
	std::cout << "|  INDEX   |FIRST_NAME| LASTNAME | NICKNAME |" << std::endl;
	std::cout << "|---------- ---------- ----------- ---------|" << std::endl;
	if (i == 0 && this->contacts[i].name.empty() && j == -99)
		std::cout << "|Your PhoneBook is empty... :(               |" <<  std::endl;
	while(!this->contacts[i].name.empty())
	{	
		std::cout << "|         " << i;
		this->contacts[i].print_short();
		if(resetted == 1)
			if(i == j)
				break;
		if(i == 7)
		{
			if(j == -99)
				break;
			else
			{
				i = j - 1;
				resetted = 1;
			}
		}
		i++;
	}
	std::cout << "**********************************************" << std::endl << std::endl;
}


void PhoneBook::search_contact()
{
	int index;
	std::cout << "Select the contact you want to by their index" << std::endl;
	std::cin >> index;
	if(this->over_count && index >= this->contact_count)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	else if(!this->over_count && index >= 8)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	this->contacts[index].print();
}