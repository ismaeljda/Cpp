#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}
Span::~Span() {}
Span::Span(const Span& copy) : _N(copy._N) {}
Span& Span::operator=(const Span& src)
{
    if (this != &src)
    {
        this->_N = src._N;
    }
}

void Span::addNumber(const int i)
{
    if (this->vec.size() > _N)
    {
        throw FullContainerException();
    }
    vec.push_back(i);
}

const char* Span::FullContainerException::what() const throw()
{
    return ("This container is full");
}

const char* Span::NoNumberStored::what() const throw()
{
    return ("There's no number stored or only one");
}

void Span::display()
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

int Span::longestSpan()
{
    if (vec.size() <= 1)
        throw NoNumberStored();
    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    return max - min;
}

int Span::shortestSpan()
{
    if (vec.size() <= 1)
        throw NoNumberStored();
    int min = INT_MAX;
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i + 1] - vec[i] < min)
            min = vec[i + 1] - vec[i];
    }
    return min;
}

void Span::addNumbers(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count ; ++i)
    {
        int num = va_arg(args, int);
        if (vec.size() > this->_N)
            throw FullContainerException();
        vec.push_back(num);
    }
    va_end(args);
}

void Span::printNumbers() const 
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void Span::addMultiple(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(std::distance(begin,end) + vec.size() > _N)
        throw FullContainerException();
    vec.insert(vec.end(), begin, end);
}