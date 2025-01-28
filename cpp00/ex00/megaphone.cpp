#include <iostream>

void upper(const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            std::cout << (char)(str[i] - 32);
        else
            std::cout << str[i];
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while (i < ac)
        {
            upper(av[i]);
            i++;
        }
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}
