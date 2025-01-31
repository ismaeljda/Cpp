#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default_clap_name"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "Clap Trap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "Clap Trap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Clap Trap Default Destructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& copy) : _name(copy._name), _hit_point(copy._hit_point),
    _energy_point(copy._energy_point), _attack_damage(copy._attack_damage)
{
    std::cout << "Clap Trap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
    std::cout << "Assignement operator called" << std::endl;
    if (this != &src)
    {
        this->_name = src._name;
        this->_hit_point = src._hit_point;
        this->_energy_point = src._energy_point;
        this->_attack_damage =src._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_point > 0 && this->_energy_point > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " 
        << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_point--;
    }
    else if (this->_energy_point == 0)
    {
        std::cout << this->_name << " can't attack because he has no energy point left."<< std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_point > amount)
        this->_hit_point -= amount;
    else
        this->_hit_point = 0;
    std::cout << this->_name << " has now  " << _hit_point << " HP left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_point > 0 && (this->_energy_point > 0 && this->_hit_point + amount <= 10))
    {
        std::cout << this->_name << " gained " << amount << " HP " << std::endl;
        this->_hit_point += amount;
        this->_energy_point--;
    }
    else if (this->_hit_point == 0)
    {
        std::cout << this->_name << " can't be repaired because he is dead " << std::endl;
    }
    else if (this->_energy_point == 0)
    {
        std::cout << this->_name << " doesn't have enough energy points " << std::endl;
    }
    else
    {
        std::cout << this->_name << " can't gain more HP because has already 10 HP " << std::endl;
    }
}