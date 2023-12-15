/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:02:16 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/23 23:07:26 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals()
			<< std::endl;
}


Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;

	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << _amount << ";"
			<< "nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;

	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ";"
			<< "amount:" << _amount << ";"
			<< "nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals
			<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t currentTime = time(0);
	tm* localTime = localtime(&currentTime);

	std::cout << "[" << (1900 + localTime->tm_year)
			<< std::setfill('0') << std::setw(2) << (localTime->tm_mon + 1)
			<< std::setfill('0') << std::setw(2) << localTime->tm_mday
			<< "_"
			<< std::setfill('0') << std::setw(2) << localTime->tm_hour
			<< std::setfill('0') << std::setw(2) << localTime->tm_min
			<< std::setfill('0') << std::setw(2) << localTime->tm_sec
			<< "]";
}

Account::Account( void )
{
	
}
