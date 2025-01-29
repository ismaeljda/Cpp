#include <iostream>
#include <fstream>
#include <string>

void read_replace (std::string filename, std::string s1, std::string s2)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Impossible to open this file" << std::endl;
        return ;
    }

    std::ofstream outfile(filename + ".replace");
    if (!outfile)
    {
        std::cerr << "Impossible to create this file" << std::endl;
        return ;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    inputFile.close();
    outfile.close();
}

int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Wrong number of arguments" <<std::endl;
        return (1);
    }
    std::string filename = av[1], s1 = av[2], s2 = av[3];
    read_replace(filename, s1, s2);
}