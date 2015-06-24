#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include <string>
#include <map>

using namespace std;

class MoneyMarket
{
public:
	MoneyMarket();
	~MoneyMarket();
	double get_balance();
	string get_name();

protected:
	string m_name;
	double m_balance;
	
};

#endif