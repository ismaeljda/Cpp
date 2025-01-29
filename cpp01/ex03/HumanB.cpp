#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon_type(nullptr) {}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon_type = &weapon;
}

void HumanB::attack()const
{
    if (_weapon_type)
        std::cout << _name << " attacks with their " << _weapon_type->getType() << std::endl;
    else 
        std::cout << "No weapon" << std::endl;
}