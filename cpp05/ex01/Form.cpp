#include "Form.hpp"

Form::~Form() {}

Form::Form(const std::string name, const int signGrade, const int exGrade) : _name(name), _signGrade(signGrade), _exGrade(exGrade), _signed(0)
{
    if (_signGrade > MAX_GRADE || _exGrade > MAX_GRADE)
        throw Bureaucrat::GradeToolowException();
    else if (_signGrade < MIN_GRADE || _exGrade < MIN_GRADE)
        throw Bureaucrat::GradeTooHighException();
}

Form::Form(const Form& copy) : _name(copy._name), _signGrade(copy._signGrade), _exGrade(copy._exGrade), _signed(copy._signed) {}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
    {
        this->_signed = src._signed;
    }
    return *this;
}

const std::string Form::getName(void) const
{
    return this->_name;
}
const int Form::getSignGrade(void) const
{
    return this->_signGrade;
}
const int Form::getExGrade(void) const
{
    return this->_exGrade;
}
bool Form::getStatus(void) const
{
    return this->_signed;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* Form::AlreadySignedException::what() const throw()
{
    return "this form has already been signed!";
}

void Form::beSigned(Bureaucrat& Bureaucrat)
{
    if (this->getStatus() == true)
        throw AlreadySignedException();
    if (Bureaucrat.getGrade() <= this->_signGrade)
        this->_signed = 1;
    else 
        throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream &o, const Form& Form) 
{
	o	<< Form.getName() << ", Form needs "
		<< Form.getSignGrade() << "to be signed and needs"
        << Form.getExGrade() << "to be executed" 
        << std::endl;
	return o;
}