#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include "contact.hpp"
#include "utils.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
        int count;

    public:
        PhoneBook() : count(0) {} 
        void add_contact(std::string first_name, std::string last_name, std::string nickname, std::string darkest_secret, std::string number);
        void search_contact(void);
};
void add(PhoneBook& phonebook);

#endif