#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex
	          << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	          << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {}

int	Account::getTotalAmount(void) {}

int	Account::getNbDeposits(void) {}

int	Account::getNbWithdrawals(void) {}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
		      << ";total:" << Account::_totalAmount
			  << ";deposits:" << Account::_totalNbDeposits
			  << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {

	std::time_get<char>();
	std::cout << "[timestamp_time] ";
}

void		Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex
	          << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit
			  << ";amount:" << (this->_amount + deposit)
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
}

bool		Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	if (withdrawal <= this->_amount) {
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex
		          << ";p_amount:" << this->_accountIndex
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << (this->_amount - withdrawal)
				  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	else {
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_accountIndex
				  << ";withdrawal:refused" << std::endl;
	}
}

int			Account::checkAmount( void ) const {}

void		Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	          << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_totalNbWithdrawals << std::endl;
}

