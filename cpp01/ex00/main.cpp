#include "Zombie.hpp"

int main()
{
    Zombie *foo = newZombie("foo");
    delete foo;
    std::cout << "////" << std::endl;
    randomChump("coo");
}