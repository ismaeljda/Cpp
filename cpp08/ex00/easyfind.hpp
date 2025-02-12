#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <algorithm>
# include <exception>
# include <iostream>

template <typename T>

typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
#endif