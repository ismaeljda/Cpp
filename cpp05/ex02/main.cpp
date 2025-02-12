#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Création des bureaucrates avec différents grades
        Bureaucrat boss("Big Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 150);

        // Création des formulaires avec différentes cibles
        ShrubberyCreationForm shrubberyForm("Garden");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Arthur Dent");

        std::cout << "\n=== Test avec Intern (trop faible) ===\n";
        try {
            intern.signForm(shrubberyForm);
            boss.signForm(shrubberyForm);
            intern.executeForm(shrubberyForm);
        } catch (std::exception &e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }

        std::cout << "\n=== Manager signe et tente d'exécuter ShrubberyCreationForm ===\n";
        try {
            manager.signForm(shrubberyForm);
            if (shrubberyForm.getStatus())
                manager.executeForm(shrubberyForm);
        } catch (std::exception &e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }

        std::cout << "\n=== Boss signe et exécute tous les formulaires ===\n";
        try {
            boss.signForm(robotomyForm);
            if (robotomyForm.getStatus())
                boss.executeForm(robotomyForm);

            
            boss.signForm(pardonForm);
            boss.executeForm(pardonForm);
        } catch (std::exception &e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }

    } catch (std::exception &e) {
        std::cerr << "Fatal exception: " << e.what() << "\n";
    }

    return 0;
}
