#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
        int count;

    public:
        PhoneBook() : count(0) {} 
        void add_contact(std::string first_name, std::string last_name, std::string nickname, std::string darkest_secret, std::string number);
};

#endif