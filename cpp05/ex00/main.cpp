#include "Bureaucrat.hpp"

int main ()
{
    try 
    {
        Bureaucrat mr("bruno", 2);
        mr.increment(3);
    }
	catch (std::exception& e) 
    {
		std::cout << "Error: " << e.what() << std::endl;
	}
}