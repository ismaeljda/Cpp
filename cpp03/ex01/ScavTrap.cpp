#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap& copy) : ClapTrap(copy) 
{
    std::cout << "ScavTrap copy Constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in gate keeping mode" << std::endl;
}