#include "AForm.hpp"

AForm::~AForm() {}

AForm::AForm(const std::string name, const int signGrade, const int exGrade, std::string target) : _name(name), _signGrade(signGrade), _exGrade(exGrade), _signed(0), _target(target)
{
    if (_signGrade > MAX_GRADE || _exGrade > MAX_GRADE)
        throw Bureaucrat::GradeToolowException();
    else if (_signGrade < MIN_GRADE || _exGrade < MIN_GRADE)
        throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signGrade(copy._signGrade), _exGrade(copy._exGrade), _signed(copy._signed), _target(copy._target) {}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
    {
        this->_signed = src._signed;
    }
    return *this;
}

const std::string AForm::getName(void) const
{
    return this->_name;
}
const int AForm::getSignGrade(void) const
{
    return this->_signGrade;
}
const int AForm::getExGrade(void) const
{
    return this->_exGrade;
}
bool AForm::getStatus(void) const
{
    return this->_signed;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return "this Form has already been signed!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "this Form has to be signed first!";
}

void AForm::beSigned(Bureaucrat& Bureaucrat)
{
    if (this->getStatus() == true)
        throw AlreadySignedException();
    if (Bureaucrat.getGrade() <= this->_signGrade)
        this->_signed = 1;
    else 
        throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream &o, const AForm& AForm) 
{
	o	<< AForm.getName() << ", AForm needs "
		<< AForm.getSignGrade() << "to be signed and needs"
        << AForm.getExGrade() << "to be executed" 
        << std::endl;
	return o;
}

void AForm::execute(Bureaucrat const &executor)const
{
    if (this->getStatus())
    {
        if (executor.getGrade() <= this->getExGrade())
        {
            executeAction(executor);
        }
        else
            throw GradeTooLowException();
    }
    else
    {
        throw NotSignedException();
    }
}

void AForm::executeAction(Bureaucrat const &executor)const
{
    (void) executor;
}