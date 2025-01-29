#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

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

std::string format_text(std::string text, size_t width)
{
	if (text.length() > width)
		return text.substr(0, width - 1) + ".";
	return std::string(width - text.length(), ' ') + text;
}
void PhoneBook::search_contact(void)
{
	int index;
	size_t width = 10;
	std::string separator = "|";
	std::cout << format_text("Index", width) << separator;
	std::cout << format_text("First Name", width) << separator;
	std::cout << format_text("Last Name", width) << separator;
	std::cout << format_text("Nickname", width) <<std::endl;

	for (int i = 0; i < 44; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout <<  "         " << i << separator;
		std::cout << format_text(contact[i].get_first_name(), width) << separator;
		std::cout << format_text(contact[i].get_last_name(), width) << separator;
		std::cout << format_text(contact[i].get_nickname(), width) <<std::endl;
	}
	do {
	std::cout << "Select an index: ";
	std::cin >> index;
	if (index == -1)
		return ;
	if (count > 0 && (index >= 0 && index < count))
		contact[index].display_contact();
	else
		std::cout << "Error: Choose an index in the list or write -1 to exit" << std::endl;
	}
	while (count > 0 && (index < 0 || index >= count));
}
 
void add(PhoneBook& phonebook)
{
    std::string first_name, last_name, nickname, darkest_secret;
	std::string number;
	std::cout << "Fill in the following fields" << std::endl;
    do
		{
			std::cout << "First name: ";
			std::getline(std::cin, first_name);
            first_name = trim(first_name);
			if (first_name.empty())
			{
				std::cout << "First name cannot be empty. Please enter a valid name." << std::endl;
			}
		} while (first_name.empty());

		do
		{
			std::cout << "Last name: ";
			std::getline(std::cin, last_name);
            last_name = trim(last_name);
			if (last_name.empty())
			{
				std::cout << "Last name cannot be empty. Please enter a valid last name." << std::endl;
			}
		} while (last_name.empty());

		do
		{
			std::cout << "Nickname: ";
			std::getline(std::cin, nickname);
            nickname = trim(nickname);
			if (nickname.empty())
			{
				std::cout << "Nickname cannot be empty. Please enter a valid nickname." << std::endl;
			}
		} while (nickname.empty());

		do
		{
			std::cout << "Darkest secret: ";
			std::getline(std::cin, darkest_secret);
            darkest_secret = trim(darkest_secret);
			if (darkest_secret.empty())
			{
				std::cout << "Darkest secret cannot be empty. Please enter a valid secret." << std::endl;
			}
		} 
        while (darkest_secret.empty());

		do {
        std::cout << "Your number: ";
        std::getline(std::cin, number);
        number = trim(number);
        if (is_digit(number)) {
            std::cout << "Number must be digit only. Please enter a valid number." << std::endl;
        }
		if (number.empty())
		{
				std::cout << "Number cannot be empty. Please enter a valid secret." << std::endl;
		}
    } while (is_digit(number) || number.empty());
    phonebook.add_contact(first_name, last_name, nickname, darkest_secret,number);
}