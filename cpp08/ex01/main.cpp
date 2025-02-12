#include "Span.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime> 

int main ()
{
    //test insert 1 a la fois
    Span span_1(10);
    span_1.addNumber(5);
    span_1.addNumber(8);
    span_1.addNumber(9);
    span_1.addNumber(4);
    span_1.addNumber(12);
    try
    {
        std::cout << "Longest span: ";
        std::cout << span_1.longestSpan()<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Shortest span: ";
        std::cout << span_1.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //Test multiple insert
    std::vector<int> vec_1;
    srand(time(0));
    for (int i = 0; i < 10000; i++)
    {
        int num = rand() % 10000;
        vec_1.push_back(num);
    }
    Span span(10000);
    try
    {
        span.addMultiple(vec_1.begin(), vec_1.end());
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Longest span: " ;
        std::cout << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Shortest span: ";
        std::cout << span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}