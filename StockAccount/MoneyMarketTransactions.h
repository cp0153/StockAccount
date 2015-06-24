#ifndef MONEYMARKETTRANSACTIONS_H
#define MONEYMARKETTRANSACTIONS_H

#include <iostream>
#include <string>
#include <map>
#include "MoneyMarket.h"

using namespace std;

class MMTransactions : public MoneyMarket
{
public:
	MMTransactions();
	virtual ~MMTransactions();
	int withdraw();
	int deposit();
	void output();
	double get_balance();

protected:
	map < int, double > transaction;
	double amount;
	int m_key = 1;
};
#endif