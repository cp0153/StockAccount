#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include <string>
#include <map>


class MoneyMarket
{
public:
	MoneyMarket();
	~MoneyMarket();
	double get_balance();
	std::string get_name();

protected:
	std::string m_name;
	double m_balance;
	
};

#endif