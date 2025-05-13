#include "PMergeMe.hpp"

PmergeMe::PmergeMe()
{

}
PmergeMe::~PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe& copy)
{
    this->vec = copy.vec;
    this->deq = copy.deq;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src)
    {
        this->vec = src.vec;
        this->deq = src.deq;
    }
    return *this;
}

void PmergeMe::Load_Chek(std::string& str)
{
    std::istringstream iss(str);
    std::string token;

    while (iss >> token)
    {
        if (!isPositiveNumber(token))
        {
            std::cerr << "Error: invalid token '" << token << "'" << std::endl;
            return; 
        }

        std::istringstream conv(token);
        unsigned long long value;
        conv >> value;
        if (value > INT_MAX)
        {
            std::cerr << "Error: not an int number '" << token << "'" << std::endl;
            return; 
        }
        int val = static_cast<int>(value);
        this->deq.push_back(val);
        this->vec.push_back(val);
    }

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sort()
{
    int i = 0; 
    std::vector<int> main;
    std::vector<int> pending;

    while(i < this->vec.size())
    {
        if (i == vec.size() - 1)
        {
            main.push_back(vec[i]);
        }
        else if (vec[i] >= vec[i + 1])
        {
            main.push_back(vec[i]);
            pending.push_back(vec[i + 1]);
        }
        else
        {
            main.push_back(vec[i + 1]);
            pending.push_back(vec[i]);
        }
        i += 2;
    }
    sort();
    if (main.size() <= 1)
    {
        return ;
    }
}

