#ifndef MONEYMARKETTRANSACTIONS_H
#define MONEYMARKETTRANSACTIONS_H

#include <iostream>
#include <string>
#include <map>
#include "MoneyMarket.h"


class MMTransactions : public MoneyMarket
{
public:
	MMTransactions();
	virtual ~MMTransactions();
	bool withdraw(double amount);
	bool deposit(double amount);
	void displayRecentTransactions();
	double get_balance();
	void displayBalance();

protected:
	std::map < int, double > transaction;
	double amount;
	int m_key = 1;
};
#endif