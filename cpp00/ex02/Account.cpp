#include "Account.hpp"

// Initialisation des variables statiques
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
    std::time_t timestamp = std::time(nullptr);
    char buffer[20];
    strftime(buffer, 20, "[%Y%m%d_%H%M%S]", localtime(&timestamp));
    std::cout << buffer;
}

Account::Account(int initial_deposit)
    :_accountIndex(_nbAccounts), _amount(initial_deposit),
     _nbDeposits (0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created"<< std::endl;
}

Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount 
    << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals <<std::endl;
}

void Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount 
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount 
    << ";deposit:" << deposit;
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount 
    << ";withdrawal:"; 
    if (withdrawal > _amount)
    {
        std::cout << "refused" <<std::endl;
        return false;
    }
    else
    {
       std::cout << withdrawal;
       _nbWithdrawals++;
       _totalNbWithdrawals++;
       _amount -= withdrawal;
       _totalAmount -= withdrawal;
       std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
       return true;
    }
}

int	Account::checkAmount(void)const
{
    return _amount;
}