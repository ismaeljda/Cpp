#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

class RPN
{
    private:
        std::stack<int> stack;
        std::vector<std::string> splitBySpace(const std::string& str);
        bool isOperator(const std::string& token);
        bool is_valid(std::vector<std::string> tokens);

    public:
        RPN();
        ~RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& src);
        int convert(const std::string& str);
        class Divisionbyzero : public std::exception {
            public:
                virtual const char* what() const throw();
            };
        class WrongInput : public std::exception {
            public:
                virtual const char* what() const throw();
            };
};

#endif