/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:11:11 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/02 03:22:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>

Account::Account(int initial_deposit): _nbDeposits(initial_deposit)
{
}

Account::Account()
{
}

Account::~Account()
{
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
	std::cout << "Timestamp= " << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits = deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	this->_totalNbWithdrawals = withdrawal;
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	std::cout << this->_accountIndex << std::endl;
}

void	displayAccountsInfos( void )
{
	std::cout << "Show data of accounts" << std::endl;
}
