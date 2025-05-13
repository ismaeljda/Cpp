#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>

bool isPositiveNumber(const std::string& s);

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& src);
        void Load_Chek(std::string& str);
        void sort();
};

#endif