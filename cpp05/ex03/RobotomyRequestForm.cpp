#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", 72, 45, target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : 
AForm("Robotomy request", copy.getSignGrade(), copy.getExGrade(), copy._target){}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::executeAction(Bureaucrat const &executor) const
{
    std::cout << "**Drilling noise**" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
    {
        std::cout << _target << "has been robotomized" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed" << std::endl;
    }
}