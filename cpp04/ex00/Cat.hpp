#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
// Pas besoin de surchargeur d'affectation car déjà gérer par la classe mère et que pas de différence avec celui ci donc utilise using
class Cat : public Animal
{
    public:
        using Animal::operator=;
        Cat();
        ~Cat();
        Cat(const Cat& other);
        void makeSound() override;
};

#endif