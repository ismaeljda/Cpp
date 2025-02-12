#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int nb) 
{
    _size = nb;
    _array = new T[nb];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size)
{
    this->_array = new T[_size];
    for (int i = 0; i < _size; i++)
    {
        _array[i] = copy._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
    if(this != &src)
    {
        delete[] _array;
        _size = src._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
        {
            _array[i] = src._array[i];
        }
    }
    return *this;
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw IndexTooHigh();
    return this->_array[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw IndexTooHigh();
    return this->_array[index];
}

template <typename T>
const char* Array<T>::IndexTooHigh::what() const throw()
{
    return "Index invalid";
}

template <typename T>
size_t Array<T>::Size() const
{
    return this->_size;
}