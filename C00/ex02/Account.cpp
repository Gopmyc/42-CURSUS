/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:43:04 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/06/22 03:19:57 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>


int Account::_nbAccounts			=	0;
int Account::_totalAmount			=	0;
int Account::_totalNbDeposits		=	0;
int Account::_totalNbWithdrawals	=	0;


Account::Account(int initial_deposit)
	:
		_accountIndex(Account::_nbAccounts++),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	Account::_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex
				<< ";amount:"	<< _amount
				<< ";created"	<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:"	<< this->_amount
				<< ";closed"	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm*	lt = std::localtime(&now);

	std::cout	<< "["
				<< (lt->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << lt->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << lt->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << lt->tm_hour
				<< std::setw(2) << std::setfill('0') << lt->tm_min
				<< std::setw(2) << std::setfill('0') << lt->tm_sec
				<< "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:"		<< _nbAccounts
				<< ";total:"		<< _totalAmount
				<< ";deposits:"		<< _totalNbDeposits
				<< ";withdrawals:"	<< _totalNbWithdrawals
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	int prevAmount = this->_amount;

	this->_amount += deposit;
	++this->_nbDeposits;

	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;

	_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";p_amount:"		<< prevAmount
				<< ";deposit:"		<< deposit
				<< ";amount:"		<< this->_amount
				<< ";nb_deposits:"	<< this->_nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int prevAmount = this->_amount;

	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout	<< "index:"		<< this->_accountIndex
					<< ";p_amount:"	<< prevAmount
					<< ";withdrawal:refused" << std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	++this->_nbWithdrawals;

	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;

	_displayTimestamp();
	std::cout	<< "index:"				<< this->_accountIndex
				<< ";p_amount:"			<< prevAmount
				<< ";withdrawal:"		<< withdrawal
				<< ";amount:"			<< this->_amount
				<< ";nb_withdrawals:"	<< this->_nbWithdrawals
				<< std::endl;
	return true;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:"	<< this->_amount
				<< ";deposits:"	<< this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}


int Account::checkAmount( void ) const { return (this->_amount);}

int Account::getNbAccounts( void ) { return (Account::_nbAccounts); }
int Account::getTotalAmount( void ) { return (Account::_totalAmount); }
int Account::getNbDeposits( void ) { return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals( void ) { return (Account::_totalNbWithdrawals); }