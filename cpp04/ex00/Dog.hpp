#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        using Animal::operator=;
        Dog();
        ~Dog();
        Dog(const Dog& other);
        void makeSound() override;
};

#endif