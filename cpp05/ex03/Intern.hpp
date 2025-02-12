#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& copy);
        Intern &operator=(const Intern& src);
        AForm* makeForm(const std::string form_name, const std::string target);
};
#endif