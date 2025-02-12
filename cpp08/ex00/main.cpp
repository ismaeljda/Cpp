#include "easyfind.hpp"

int main() 
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    try 
    {
        auto it = easyfind(numbers, 3);
        std::cout << "Element found: " << *it << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}