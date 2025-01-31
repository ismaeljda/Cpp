#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional = 8;

//Constructor
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

Fixed::Fixed (const int input)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed_point = input << this->_fractional;
}

Fixed::Fixed (const float input)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixed_point = roundf(input * (1 << this->_fractional));
}

//Getter and setter

int Fixed::getRawBits()const
{
    std::cout << "GetRawBits member function called" << std::endl;
    return _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}

//Surchargeur

Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << "copy assignement operator called" << std::endl;
    if (this != &src)
    {
        this->_fixed_point = src.getRawBits();
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
}
// Surchargeur condition
bool Fixed::operator<(const Fixed& src) const
{
    return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>(const Fixed& src) const
{
    return (this->toFloat() > src.toFloat());
}

bool Fixed::operator==(const Fixed& src) const
{
    return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(const Fixed& src) const
{
    return (this->toFloat() != src.toFloat());
}

bool Fixed::operator<=(const Fixed& src) const
{
    return (this->toFloat() <= src.toFloat());
}

bool Fixed::operator>=(const Fixed& src) const
{
    return (this->toFloat() >= src.toFloat());
}

// Surchargeur arithmetique

Fixed Fixed::operator+(const Fixed& src) const
{
    return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed& src) const
{
    return (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed& src) const
{
    return (this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed& src) const
{
    return (this->toFloat() / src.toFloat());
}

//surchargeur incrementation

Fixed& Fixed::operator++()
{
    this->_fixed_point++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->_fixed_point--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixed_point++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixed_point--;
    return temp;
}
//Function

int Fixed::toInt( void ) const
{
    return this->_fixed_point >> _fractional;
}

float Fixed::toFloat( void ) const
{
    return (float)this->_fixed_point / (float) (1 << _fractional);
}

// min max function

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.toFloat() > b.toFloat())
        return a;
    else
        return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.toFloat() < b.toFloat())
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.toFloat() > b.toFloat())
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.toFloat() < b.toFloat())
        return a;
    else
        return b;
}