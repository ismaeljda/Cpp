#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " is dead..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    _name = name;
}