#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5, target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
AForm("Presidential Pardon", copy.getSignGrade(), copy.getExGrade(), copy._target){}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::executeAction(Bureaucrat const &executor) const
{
    std::cout << _target << "has been pardonned by Zaphod Beeblebrox" << std::endl;
}