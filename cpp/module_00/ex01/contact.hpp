#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
		std::string secret;
	public:
		std::string name;
		std::string surname;
		std::string phone_number;
		std::string nickname;
		Contact();
		Contact(std::string name, std::string surname, std::string phone_number, std::string nickname, std::string secret);
		std::string get_secret();
		void print_short();
		void print();
};

#endif