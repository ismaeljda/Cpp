#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	std::string answer, first_name, last_name, nickname, darkest_secret;
	std::string number;
    PhoneBook phonebook;

	std::cout << "ADD, SEARCH ou EXIT" << std::endl;
	std::cin >> answer;
	if (answer == "ADD")
	{
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
    } while (is_digit(number));
		// phonebook.add_contact(first_name, last_name, nickname, darkest_secret,number);
	}

	// if (answer == "SEARCH")
	// {

	// }
}