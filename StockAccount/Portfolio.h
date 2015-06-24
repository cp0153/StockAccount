#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <map>
#include "StockTransactions.h"

class Portfolio
{
public:
	Portfolio();
	~Portfolio();
private:
	std::map < int, StockTransactions > m_stockLedger;
	double m_gainLoss;
	double m_totalValue;
	int m_key;
};

#endif