#include "Cat.hpp"
#include "Dog.hpp"

// int main() 
// {
//     std::cout << "==== Création d'un tableau d'Animaux ====" << std::endl;
//     Animal* animals[4];

//     // Remplissage du tableau avec Dogs et Cats
//     for (int i = 0; i < 2; i++) {
//         animals[i] = new Dog();
//     }
//     for (int i = 2; i < 4; i++) {
//         animals[i] = new Cat();
//     }

//     std::cout << "\n==== Test des sons des animaux ====" << std::endl;
//     for (int i = 0; i < 4; i++) {
//         animals[i]->makeSound();
//     }

//     std::cout << "\n==== Suppression des animaux ====" << std::endl;
//     for (int i = 0; i < 4; i++) {
//         delete animals[i];
//     }

//     std::cout << "\n==== Test d'affectation et de copie ====" << std::endl;
//     Dog dog1;
//     Dog dog2 = dog1;  // Test constructeur de copie
//     Dog dog3;
//     dog3 = dog1;      // Test opérateur d'affectation

//     std::cout << "\n==== Fin du programme ====" << std::endl;
//     return 0;
// }

int main() {
    Animal* animal = new Dog();  // Pointeur de base (Animal*) qui pointe vers un objet dérivé (Dog)
    delete animal;  // Suppression de l'objet via un pointeur de base
    // Résultat : Le destructeur de Dog ne sera pas appelé !
    return 0;
}