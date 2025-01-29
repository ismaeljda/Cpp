#include <iostream>

int main() 
{
    std::string brain = "HI THIS IS BRAIN";

    //pointeur sur la variable 
    std::string* stringPTR = &brain;

    //référence sur la variable 
    std::string& stringREF = brain;

    // adresses mémoire
    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // valeurs
    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    
    return 0;
}