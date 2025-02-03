#include "Animal.hpp"

Animal::Animal() 
{
    std::cout << "Default constructor Animal called" << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Destructor Animal called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Copy constructor Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
    if (this == &src)
    {
      this->_type = src._type;  
    }
    return (*this);
}

void  Animal::makeSound()
{
    std::cout << "Some random animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}