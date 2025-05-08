#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}
BitcoinExchange::~BitcoinExchange()
{

}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
    this->bitcoinPrices = copy.bitcoinPrices;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src) {
        this->bitcoinPrices = src.bitcoinPrices;
    }
    return *this;
}
BitcoinExchange::InvalidDateException::InvalidDateException(const std::string& input) 
{
    this->_msg = "Error: bad input => " + input;
}
const char* BitcoinExchange::InvalidDateException::what() const throw() 
{
    return this->_msg.c_str();
}
const char* BitcoinExchange::TooLargeNumber::what() const throw()
{
    return "Error: Too large a number.";
}
const char* BitcoinExchange::NegativeNumber::what() const throw()
{
    return "Error: not a positive number.";
}
const char* BitcoinExchange::DateTooEarlyException::what() const throw() 
{
    return "Error: date is before 2009-01-02.";
}
//Lire le fichier
//Peut etre ajouter erreur sur parsing si element manquant meme si fichier de base fonctionne bien
void BitcoinExchange::Load_read_file(const std::string& filename)
{
    std::ifstream f (filename.c_str()); // Parce que ifstream ne pouvait pas prendre std::string dans son constructeur en c++ 98 donc on doit mettre en char *
    std::string line;
    if (f.is_open())
    {
        std::getline(f, line); //Pour sauter la 1ere ligne
        while (std::getline(f, line))
        {
            std::stringstream ss(line);
            std::string date;
            std::getline(ss, date, ',');
            std::string value;
            std::getline(ss, value, ','); 
            double valeur = std::atof(value.c_str());
            float value_2 = static_cast<float>(valeur);
            bitcoinPrices[date] = value_2;
        }
        f.close();
    }
    else
    {
        std::cerr << "Error: couldn't open the file" << std::endl;
    }
}

void BitcoinExchange::Convert(const std::string& filename)
{
    std::ifstream f (filename.c_str()); 
    std::string line;
    if (f.is_open())
    {
        std::getline(f, line);
        while (std::getline(f, line))
        {
            std::stringstream ss(line);
            std::string date, value, date_2;
            std::getline(ss, date, '|');
            std::getline(ss, value, '|'); 
            date.erase(date.length() - 1,1);
            double valeur = std::atof(value.c_str());
            float value_2 = static_cast<float>(valeur);
            try 
            {
                float price;
                float product;
                BitcoinExchange::validateDate(date);
                BitcoinExchange::isValidNumber(value_2);
                std::map<std::string, float>::iterator it = bitcoinPrices.upper_bound(date);
                std::cout << it->first << std::endl;
                // if (it != bitcoinPrices.begin() && (it == bitcoinPrices.end() || it->first != date)) 
                // {
                //     --it;
                //     price = it->second;
                // }
                // if (it != bitcoinPrices.end()) 
                // {
                //     price = it->second;
                // }
                // product = price * value_2;
                // std::cout << date << " => " << value_2 << " = "<< product <<std::endl;
            }
            catch (const BitcoinExchange::InvalidDateException& e) 
            {
                std::cerr << e.what() << std::endl;
            }
            catch (const BitcoinExchange::TooLargeNumber& e) 
            {
                std::cerr << e.what() << std::endl;
            }
            catch (const BitcoinExchange::NegativeNumber& e) 
            {
                std::cerr << e.what() << std::endl;
            }
        }
        f.close();
    }
    else
    {
        std::cerr << "Error: couldn't open the file" << std::endl;
    }
}

int main(int ac, char **av)
{
    BitcoinExchange yo;
    yo.Load_read_file("data.csv");
    yo.Convert("file.txt");
}