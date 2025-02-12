#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    Intern intern;
    AForm *form;
    AForm *form_2;
    form = intern.makeForm("dhgdhgd", "home");
    if (form)
        delete form;
    form_2 = intern.makeForm("PresidentialPardonForm", "home");
    if (form_2)
        delete form_2;
    return 0;
}
