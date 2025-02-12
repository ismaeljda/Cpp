#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

# define MIN_GRADE 1
# define MAX_GRADE 150

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat& src);
        const std::string getName(void) const;
        int getGrade(void) const;
        //Function
        void decrement(int nb);
        void increment(int nb);
        void signForm(AForm& form);
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception // what renvoie un message d'erreur fonction de la classe std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeToolowException : public std::exception
        {
            virtual const char* what() const throw();
        };
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);

#endif