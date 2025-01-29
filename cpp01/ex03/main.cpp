#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();

    club.setType("sword");
    bob.attack(); 

    HumanB bill("bill");
    bill.attack();

    bill.setWeapon(club);
    bill.attack(); 
}