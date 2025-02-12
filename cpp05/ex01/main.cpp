#include "Bureaucrat.hpp"

int main ()
{
    try 
    {
        Form fichier("fichier", 150, 151);
        Bureaucrat Denis("Denis", 6);
        Denis.signForm(fichier);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}