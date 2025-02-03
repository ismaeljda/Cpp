#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal &operator=(const Animal& src);
        virtual void  makeSound();
        std::string getType() const;
};

#endif