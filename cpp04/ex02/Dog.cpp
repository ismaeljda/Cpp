#include "Dog.hpp"

Dog::Dog() 
{
    this->_type = "Dog";
    this->brain = new Brain;
    std::cout << "Default constructor Dog called" << std::endl;
}

Dog::~Dog() 
{
    delete this->brain;
    std::cout << "Destructor Dog called" << std::endl;
}

//other.brain est un pointeur qui stocke une valeur (un object de type brain) 
//nous on veut creer une copie de cette valeur donc on déréférence le pointeur pour accéder à la valeur
Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*other.brain); 
    std::cout << "Copy constructor Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}

void  Dog::makeSound()
{
    std::cout << "Wouuuf" << std::endl;
}