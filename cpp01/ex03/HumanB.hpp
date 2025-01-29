#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon_type;
        
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack()const;
};
#endif