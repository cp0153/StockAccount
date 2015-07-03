#ifndef MONEYMARKETTRANSACTIONS_H
#define MONEYMARKETTRANSACTIONS_H

#include <iostream>
#include <map>
#include "MoneyMarket.h"


class MMTransactions : public MoneyMarket
{
public:
	MMTransactions();
	MMTransactions(std::string name, double balance);
	~MMTransactions();
	bool withdraw(double amount);
	bool deposit(double amount);
	void displayRecentTransactions();
	double get_balance();
	void displayBalance();

private:
	std::map < int, double > transaction;
	int m_key;
};
#endif
