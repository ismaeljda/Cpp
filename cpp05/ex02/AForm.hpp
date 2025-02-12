#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm
{
    protected:
        std::string _target;
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _exGrade;
    public:
        AForm(const std::string name, const int signGrade, const int exGrade, std::string target);
        AForm(const AForm& copy);
        ~AForm();
        AForm &operator=(const AForm& src);
        //Getter 
        const std::string getName(void) const;
        const int getSignGrade(void) const;
        const int getExGrade(void) const;
        bool getStatus(void) const;
        //function
        virtual void beSigned(Bureaucrat& Bureaucrat);
        virtual void execute(Bureaucrat const &executor) const;
        virtual void executeAction(Bureaucrat const &executor) const = 0;
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

        class NotSignedException : public std::exception
        {
            virtual const char* what() const throw();
        };

};

std::ostream&	operator<<(std::ostream &o, const AForm& AForm);

#endif