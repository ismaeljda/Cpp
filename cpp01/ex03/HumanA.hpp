#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon_type;
        
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack()const;
};
#endif