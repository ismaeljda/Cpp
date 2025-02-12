#include "intern.hpp"

Intern::Intern() {}
Intern::~Intern(){}
Intern::Intern(const Intern& copy){}
Intern& Intern::operator=(const Intern& src)
{
    return *this;
}

AForm* new_shrub (const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* new_robot (const std::string target)
{
    return new RobotomyRequestForm(target);
}
        
AForm* new_pardon (const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string form_name, const std::string target_form)
{
    AForm* (*all_form[])(const std::string target) = {&new_shrub, &new_robot, &new_pardon};
    std::string form[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    for (int i = 0; i < 3; i++)
    {
        if (form_name == form[i])
        {
            std::cout << "Intern creates " << form_name << " now" << std::endl;
            return (all_form[i](target_form));
        }
    }
    std::cout << "Intern couldn't create " << form_name << std::endl;
    return (nullptr);
}
