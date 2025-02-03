#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{
    Animal* a1 = new Dog();  // Création d'un objet Dog sous un pointeur Animal
    Animal* a2 = new Cat();  // Création d'un objet Cat sous un pointeur Animal

    a1->makeSound();  // Affichera "Woof!" (si `makeSound()` est bien défini dans `Dog`)
    a2->makeSound();  // Affichera "Meow!" (si `makeSound()` est bien défini dans `Cat`)
    
    std::cout << a1->getType() << std::endl; // Devrait afficher "Dog"
    std::cout << a2->getType() << std::endl; // Devrait afficher "Cat"

    delete a1; // Nettoyage mémoire
    delete a2;

    return 0;
}