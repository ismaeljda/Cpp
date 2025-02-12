#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry Creation", 145, 137, target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : 
AForm("Shruberry Creation", copy.getSignGrade(), copy.getExGrade(), copy._target){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const
{
    std::ofstream file(_target + "_shrubbery");
    if (file.is_open())
    {
        file << "      ###\n"
             << "     #o##\n"
             << "    #oo###\n"
             << "   #ooo####\n"
             << "  #oooo#####\n"
             << " #####|||||\n"
             << "      |||\n"
             << "      |||\n";
        file.close();
        std::cout << "Shrubbery created in " << _target << "_shrubbery file.\n";
    } 
    else 
    {
        std::cerr << "Error: Could not create shrubbery file.\n";
    }
}