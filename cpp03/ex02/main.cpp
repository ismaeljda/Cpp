#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
    ScavTrap c("bil");
    FragTrap f("tony");
    c.guardGate();
    f.highFivesGuys();
}