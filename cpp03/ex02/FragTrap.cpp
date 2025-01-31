#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
    _hit_point = 100;
    _energy_point = 100;
    _attack_damage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hit_point = 100;
    _energy_point = 100;
    _attack_damage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap (const FragTrap& copy) : ClapTrap(copy) 
{
    std::cout << "FragTrap copy Constructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " wants to do an high five" << std::endl;
}