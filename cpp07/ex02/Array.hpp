#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T* _array;
        size_t _size;  
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array& copy);
        Array& operator=(const Array& src);
        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
        size_t Size()const;
        class IndexTooHigh : public std::exception
        {
            virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif