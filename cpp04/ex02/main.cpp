#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Animal* animal1 = new Dog();  // Pointeur de type Animal qui pointe vers un Dog
    Animal* animal2 = new Cat();  // Pointeur de type Animal qui pointe vers un Cat

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;
    return 0;
}