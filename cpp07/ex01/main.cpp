#include "iter.hpp"

void printInt(int& x) {
    std::cout << x << " ";
}

void printString(std::string& str) {
    std::cout << str << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::string words[] = {"Hello", "42", "World"};

    std::cout << "Tableau d'entiers : ";
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Tableau de strings : ";
    iter(words, 3, printString);
    std::cout << std::endl;

    return 0;
}