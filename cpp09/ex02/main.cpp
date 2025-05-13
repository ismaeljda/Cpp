#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string str = av[1];
        PmergeMe merge;
        merge.Load_Chek(str);
        merge.sort();
    }
    else
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
    }
}