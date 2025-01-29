#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levels[4] = {"debug", "info", "warning", "error"};
    int i = 0;
    while (i < 4)
    {
        if (levels[i] == level)
            break ;
        i++;
    }
    switch (i)
    {
        case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			Harl::debug();
			std::cout << "[ INFO ]" << std::endl;
			Harl::info();
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			break;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			Harl::info();
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			break;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			break;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			break;
		default:
			std::cout << "No Valid Level.\n";
			break;
    }
}