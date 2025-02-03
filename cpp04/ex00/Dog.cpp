#include "Dog.hpp"

Dog::Dog() 
{
    this->_type = "Dog";
    std::cout << "Default constructor Dog called" << std::endl;
}

Dog::~Dog() 
{
    std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy constructor Dog called" << std::endl;
}

void  Dog::makeSound()
{
    std::cout << "Wouuuf" << std::endl;
}