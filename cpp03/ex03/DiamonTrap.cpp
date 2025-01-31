#include "DiamonTrap.hpp"

DiamondTrap::DiamondTrap () : ClapTrap()
{
    std::cout << "Default constructor called"<< std::endl;
    this->_hit_point = FragTrap::_hit_point;
	this->_energy_point = ScavTrap::_energy_point;
	this->_attack_damage = FragTrap::_attack_damage;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() 
{
    this->name = name;
    std::cout << "DiamondTrap constructor called for " << this->name << std::endl;
    this->_hit_point = FragTrap::_hit_point;
	this->_energy_point = ScavTrap::_energy_point;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}