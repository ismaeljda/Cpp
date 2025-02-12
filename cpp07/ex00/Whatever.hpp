#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
T Max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

template <typename T>
T Min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
#endif