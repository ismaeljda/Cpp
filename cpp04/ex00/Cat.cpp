#include "Cat.hpp"

Cat::Cat() 
{
    this->_type = "Cat";
    std::cout << "Default constructor Cat called" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy constructor Cat called" << std::endl;
}

void  Cat::makeSound()
{
    std::cout << "Meouw" << std::endl;
}