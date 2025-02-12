#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _exGrade;
    public:
        Form(const std::string name, const int signGrade, const int exGrade);
        Form(const Form& copy);
        ~Form();
        Form &operator=(const Form& src);
        //Getter 
        const std::string getName(void) const;
        const int getSignGrade(void) const;
        const int getExGrade(void) const;
        bool getStatus(void) const;
        //function
        void beSigned(Bureaucrat& Bureaucrat);
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };

        class AlreadySignedException : public std::exception
        {
            virtual const char* what() const throw();
        };

};

std::ostream&	operator<<(std::ostream &o, const Form& Form);

#endif