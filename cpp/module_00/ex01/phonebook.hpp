# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./contact.hpp"

void check_input(std::string *name, std::string var);

class PhoneBook {
	public:
		Contact contacts[8];
		int contact_count;
		int over_count;
		PhoneBook();
		int add_contact();
		void search_contact();
		void print_contact(int id);
		void print();
};

#endif