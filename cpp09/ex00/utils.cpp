#include "BitcoinExchange.hpp"

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::validateDate(const std::string& date) 
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        throw BitcoinExchange::InvalidDateException(date);
    }

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i])) {
            throw BitcoinExchange::InvalidDateException(date);
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        throw BitcoinExchange::InvalidDateException(date);

    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        throw BitcoinExchange::InvalidDateException(date);

    if (date < "2009-01-02")
        throw BitcoinExchange::InvalidDateException(date);
}


void BitcoinExchange::isValidNumber(float nb)
{
    if (nb < 0 )
        throw BitcoinExchange::NegativeNumber();
    if (nb > 1000)
        throw BitcoinExchange::TooLargeNumber();
}