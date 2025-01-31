#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
    private:
        std::string _name;
        int _hit_point;
        int _energy_point;
        int _attack_damage;

    public:
        //Constructeur
        ClapTrap();
        ClapTrap (std::string name);
        ~ClapTrap();
        ClapTrap (const ClapTrap& copy);
        //operateur
        ClapTrap &operator=(const ClapTrap& src);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};
#endif