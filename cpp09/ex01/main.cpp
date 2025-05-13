#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) 
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        int res = rpn.convert(av[1]);
        std::cout << "The result is " << res << std::endl;
    }
    catch (const RPN::WrongInput& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const RPN::Divisionbyzero& e) 
    {
        std::cerr << e.what() << std::endl;
    }
}