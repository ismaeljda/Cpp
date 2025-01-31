#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public:
    //Constructeur
        Fixed();
        Fixed (const int input);
        Fixed (const float input);
        Fixed(const Fixed& copy);
    //Destructeur
        ~Fixed();
    //Surchageur
        Fixed &operator=(const Fixed& src);
        //Condition
        bool operator<(const Fixed& src) const;
        bool operator>(const Fixed& src) const;
        bool operator<=(const Fixed& src) const;
        bool operator>=(const Fixed& src) const;
        bool operator==(const Fixed& src) const;
        bool operator!=(const Fixed& src) const;
        //Arithmétique
        Fixed operator+(const Fixed& src) const;
        Fixed operator-(const Fixed& src) const;
        Fixed operator*(const Fixed& src) const;
        Fixed operator/(const Fixed& src) const;
        //Incrementor
        //Pre-incrementation
        Fixed &operator++();
        Fixed &operator--();
        //Post-incrementation
        Fixed operator++(int);
        Fixed operator--(int);
        //Min - max function
        static Fixed &max(Fixed& a, Fixed& b);
        static Fixed &min(Fixed& a, Fixed& b);
        static const Fixed &max(const Fixed& a, const Fixed& b);
        static const Fixed &min(const Fixed& a, const Fixed& b);
    //Getter
        int getRawBits()const;
    //Setter
        void setRawBits(int const raw);
    //function
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        int _fixed_point;
        static const int _fractional;
    
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif