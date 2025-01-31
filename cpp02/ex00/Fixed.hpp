#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public:
    //Constructeur
        Fixed();
        Fixed(const Fixed& copy);
    //Destructeur
        ~Fixed();
    //Surchageur
        Fixed &operator=(const Fixed& src);
    //Getter
        int getRawBits()const;
    //Setter
        void setRawBits(int const raw);
    private:
        int _fixed_point;
        static const int _fractional;
};
#endif