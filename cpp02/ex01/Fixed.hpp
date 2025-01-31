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