#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include <string>
using namespace std;

class MoneyMarket
{

public:
	MoneyMarket();
	~MoneyMarket();
	void output();
	double getBalance();
	string getName();

private:
	string name;
	double balance;

};

#endif