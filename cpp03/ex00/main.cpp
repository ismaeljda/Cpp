#include "ClapTrap.hpp"

int main ()
{
    ClapTrap a("bob");
    ClapTrap b("Alice");

    a.attack("Alice");
    b.takeDamage(0);
    a.beRepaired(10);
}