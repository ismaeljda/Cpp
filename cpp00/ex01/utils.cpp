#include "PhoneBook.hpp"


int is_digit(std::string nb)
{
    int i = 0;
    while (nb[i])
    {
        if (nb[i] < '0' || nb[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

std::string trim(const std::string& str)
{
    size_t start = 0;
    size_t end = str.size();

    while (start < end && std::isspace(str[start])) {
        ++start;
    }

    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }

    return str.substr(start, end - start);
}