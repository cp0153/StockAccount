#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <map>
#include "StockTransactions.h"

class Portfolio
{
public:
	Portfolio();
	~Portfolio();
	void displayRecentTransactions();
	void addTransaction();
	void displayNetValue();
	void displayGainLoss();
	double get_gainLoss();
	double get_NetValue();
	int get_key();
private:
	std::map <int, StockTransactions> m_stockLedger;
	double m_gainLoss;
	double m_NetValue;
	int m_key;
};

#endif