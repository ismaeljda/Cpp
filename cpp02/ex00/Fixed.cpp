#include "Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed() : _fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _fixed_point(copy._fixed_point)
{
    std::cout << "copy constructor called" << std::endl;
}

int Fixed::getRawBits()const
{
    std::cout << "GetRawBits member function called" << std::endl;
    return _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << "copy assignement operator called" << std::endl;
    if (this != &src)
    {
        this->_fixed_point = src.getRawBits();
    }
    return (*this);
}