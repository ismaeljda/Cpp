#include "PMergeMe.hpp"

bool isPositiveNumber(const std::string& s)
{
    if (s.empty())
        return false;
    for (std::string::size_type i = 0; i < s.length(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}
