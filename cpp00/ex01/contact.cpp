#include "contact.hpp"

void Contact::set_contact(std::string new_name, std::string new_last_name, std::string new_nickname, std::string new_darkest_secret, std::string new_number)
{
    first_name = new_name;
    last_name = new_last_name;
    nickname = new_nickname;
    darkest_secret = new_darkest_secret;
    number = new_number;
}
void Contact::display_contact()
{
    std::cout << "Name :" << first_name << std::endl;
    std::cout << "Last name :" << last_name << std::endl;
    std::cout << "Nickname :" << nickname << std::endl;
    std::cout << "Darkest secret :" << darkest_secret << std::endl;
    std::cout << "Number :" << number << std::endl;
}

std::string Contact::get_first_name(void)
{
    return (first_name);
}

std::string Contact::get_phone(void)
{
    return (number);
}

std::string Contact::get_last_name(void)
{
    return (last_name);
}

std::string Contact::get_nickname(void)
{
    return (nickname);
}

std::string Contact::get_darkest_secret(void)
{
    return (darkest_secret);
}