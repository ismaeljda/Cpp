#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) 
{
    if (_grade > MAX_GRADE)
        throw GradeToolowException();
    else if (_grade < MIN_GRADE)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
    {
        this->_grade = src._grade;
    }
    return *this;
}

const std::string Bureaucrat::getName(void) const
{
    return this->_name;
}
int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeToolowException::what() const throw()
{
    return "Grade too low!";
}

void Bureaucrat::decrement(int nb)
{
    if (this->_grade + nb > MAX_GRADE)
    {
        throw GradeToolowException();
    }
    else
    {
        this->_grade = this->_grade + nb;
    }
}

void Bureaucrat::increment(int nb)
{
    if (this->_grade - nb < MIN_GRADE)
    {
        throw GradeTooHighException();
    }
    else
    {
        this->_grade = this->_grade - nb;
    }
}

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat) 
{
	o	<< bureaucrat.getName() << ", bureaucrat of grade "
		<< bureaucrat.getGrade() << std::endl;
	return o;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because "<< e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because "<< e.what() << std::endl;
    }
    
}