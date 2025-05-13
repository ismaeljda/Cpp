#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& copy) 
{
    this->stack = copy.stack;
}
RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
    {
        this->stack = src.stack;
    }
    return *this;
}

std::vector<std::string> RPN::splitBySpace(const std::string& str) 
{
    std::istringstream iss(str);
    std::vector<std::string> tokens;
    std::string word;

    while (iss >> word) 
    {
        tokens.push_back(word);
    }

    return tokens;
}

bool RPN::isOperator(const std::string& token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}
bool RPN::is_valid(std::vector<std::string> tokens)
{
    int stackSize = 0;

    for (const std::string& token : tokens) 
    {
        if (isdigit(token[0]) && token.size() == 1) 
        {
            stackSize++;  // Un chiffre = on empile
        } 
        else if (isOperator(token)) 
        {
            if (stackSize < 2)
                return false;  // Pas assez de valeurs pour appliquer l'opérateur
            stackSize--; // On consomme 2, on empile 1 => -1
        } 
        else 
        {
            return false;  // Token inconnu
        }
    }

    return stackSize == 1;  // À la fin, il doit rester 1 seul résultat
}

int RPN::convert(const std::string& str)
{
    std::vector<std::string> tokens = splitBySpace(str);
    
    if (!is_valid(tokens))
    {
        throw RPN::WrongInput();
        return 0;
    }

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        const std::string& token = tokens[i];

        if (isdigit(token[0]) && token.size() == 1)
        {
            this->stack.push(token[0] - '0'); // convertir char en int 
        }
        else if (isOperator(token))
        {
            int b = this->stack.top(); 
            this->stack.pop();
            int a = this->stack.top(); 
            this->stack.pop();
            int res = 0;

            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/")
            {
                if (b == 0)
                {
                    throw RPN::Divisionbyzero();
                    return 0;
                }
                res = a / b;
            }

            this->stack.push(res);
        }
    }
    return this->stack.top(); // Le seul élément restant
}

const char* RPN::Divisionbyzero::what() const throw() 
{
    return "Error: division by zero";
}
const char* RPN::WrongInput::what() const throw() 
{
    return "Error: wrong input";
}
