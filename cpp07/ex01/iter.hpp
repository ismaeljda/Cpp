#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
    if (!array)
        return ;
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif