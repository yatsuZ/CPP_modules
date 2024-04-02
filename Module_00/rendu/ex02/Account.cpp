/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:11:11 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/03 00:28:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	this->_nbDeposits = 0;
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::Account()
{
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

//////////////////////////////////////////////////////

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *timestamp = std::localtime(&now);

	std::cout << "[";
	std::cout << std::setfill('0') << std::setw(4) << (timestamp->tm_year + 1900); // L'AN
	std::cout << std::setfill('0') << std::setw(2) << (timestamp->tm_mon + 1); // le mois
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mday;// Le jour
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_hour;//L'heur
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_min;//La minute
	std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_sec;//Seconde
	std::cout << "] ";
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount << std::endl;
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

