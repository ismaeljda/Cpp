#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact 
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string darkest_secret;
        std::string number;

    public:
        std::string get_first_name(void);
        std::string get_last_name(void);
        std::string get_nickname(void);
        std::string get_darkest_secret(void);
        std::string get_phone(void);
        void set_contact(std::string new_name, std::string new_last_name, std::string new_nickname, std::string new_darkest_secret, std::string new_number);
        void display_contact();
};

#endif