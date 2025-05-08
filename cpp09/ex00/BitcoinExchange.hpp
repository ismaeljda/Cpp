#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, float> bitcoinPrices;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        void Load_read_file(const std::string& filename);
        void Convert(const std::string& filename);
        void validateDate(const std::string& date);
        void isValidNumber(float nb);
        class InvalidDateException : public std::exception 
        {
            private:
                std::string _msg;
            public:
                InvalidDateException(const std::string& input);
                virtual const char* what() const throw();
        };
        class DateTooEarlyException : public std::exception {
            public:
                virtual const char* what() const throw();
            };
        class TooLargeNumber : public std::exception 
        {
            public :
                const char* what() const throw();
        };
        class NegativeNumber : public std::exception 
        {
            public:
                const char* what() const throw();
        };

};

#endif 
