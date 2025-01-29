#include "PhoneBook.hpp"
#include "utils.hpp"
#include <unistd.h>
#include <limits>

int	main(void)
{
	PhoneBook phonebook;
	while (1)
	{
		std::string answer;
		std::cout << "Select an option: ADD, SEARCH ou EXIT" << std::endl;
		std::cout << "You select: ";
		std::cin >> answer;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (answer == "ADD")
		{
			add(phonebook);
		}

		else if (answer == "SEARCH")
		{
			phonebook.search_contact();
		}
		else if (answer == "EXIT")
			exit (0);
		else
			std::cout << "Error: Choose an element between ADD, SEARCH or EXIT" << std::endl;
	}
}