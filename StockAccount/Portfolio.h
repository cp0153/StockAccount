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
	void addTransaction(StockTransactions newTrade);
	void displayCurrentValue();
	void displayOriginalvalue();
	void displayGainLoss();
	double get_gainLoss();
	double get_NetValue();
	int get_key();
private:
	std::map <int, StockTransactions> m_stockLedger;
	double m_gainLoss;
	double m_currentValue;
	double m_originalValue;
	int m_key;
	void incrementKey();
	void updateOriginalValue(StockTransactions newTrade);
};

#endif