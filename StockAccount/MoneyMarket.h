#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include <string>

class MoneyMarket
{
public:
	MoneyMarket();
	MoneyMarket(std::string name, double balance);
	virtual ~MoneyMarket();
	std::string get_name();

protected:
	std::string m_name;
	double m_balance;
};

#endif
