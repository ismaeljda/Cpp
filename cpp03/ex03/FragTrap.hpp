#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap // virtuel pour corriger les problemes d'ambiguté parce que 2 classes héritent de la même classe
{
    public:
        FragTrap();
        FragTrap (std::string name);
        ~FragTrap();
        FragTrap (const FragTrap& copy);
        void highFivesGuys(void);

};

#endif