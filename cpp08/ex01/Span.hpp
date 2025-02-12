#ifndef SPAN_HPP
# define SPAN_HPP
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstdarg>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> vec;
        Span();
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span& copy);
        Span& operator=(const Span& src);

        void addNumber(const int i);
        int shortestSpan();
        int longestSpan();
        void display();
        void addNumbers(int count, ...);
        void addMultiple(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void printNumbers()const;
        class FullContainerException : public std::exception
        {
            virtual const char *what() const throw();
        };
        class NoNumberStored : public std::exception
        {
            virtual const char *what() const throw();
        };
};

#endif