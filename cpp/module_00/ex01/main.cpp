# include "./phonebook.hpp"
#include "contact.hpp"

int ask_question()
{
	std::string response;
	std::cout << std::endl << std::endl;
	std::cout << "CHOOSE OPTION" << std::endl;
	std::cout << "1) ADD" << std::endl;
	std::cout << "2) SEARCH" << std::endl;
	std::cout << "3) EXIT" << std::endl;
	do {
		std::cin >> response;
		if(response == "ADD")
			return 1;
		else if(response == "SEARCH")
			return 2;
		else if(response == "EXIT")
			return 0;
		else
			std::cout << "Invalid option" << std::endl;
	}while (response != "ADD" && response != "SEARCH" && response != "EXIT");
	return 0;
}

void check_input(std::string *input, std::string var)
{
	int i = 0;
	do{
		if (i > 10 && i < 12)
			std::cout << "You are not trying to be funny, are you?" << std::endl;
		else if(i > 12)
		{
			*input = "U DUMB?";
			break ;
		}
		if(i > 0)
			std::cout << var << " cannot be empty" << std::endl;
		std::cout << "Enter "<< var << ": ";
		getline(std::cin, *input);
		i++;
	}
	while((*input).empty());
}

int main(void)
{
	int response = ask_question();
	PhoneBook phonebook = PhoneBook();
	while(1 && response > 0)
	{
		if(response == 1)	
			phonebook.add_contact();
		else if(response == 2)
		{
			phonebook.print();
			phonebook.search_contact();
		}
		response = ask_question();
		// break;
	}
}