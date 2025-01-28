#include "PhoneBook.hpp"

void PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string darkest_secret, std::string number)
{
    if (count < 8)
    {
        contact[count].set_contact(first_name, last_name, nickname, darkest_secret, number);
        count++;
    }
    else
    {
        for (int i = 1; i <8; i++)
            contact[i - 1] = contact[i];
        contact[7].set_contact(first_name, last_name, nickname, darkest_secret, number);
    }
}
 
