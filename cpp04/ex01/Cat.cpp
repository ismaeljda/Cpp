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

void  Cat::makeSound()
{
    std::cout << "Meouw" << std::endl;
}

//other.brain est un pointeur qui stocke une valeur (un object de type brain) 
//nous on veut creer une copie de cette valeur donc on déréférence le pointeur pour accéder à la valeur
Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain = new Brain(*other.brain); 
    std::cout << "Copy constructor Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}
