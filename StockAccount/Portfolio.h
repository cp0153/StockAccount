#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <map>
#include "StockTransactions.h"
#include "StockMarket.h"
#include "MoneyMarketTransactions.h"

class Portfolio
{
public:
	Portfolio();
	~Portfolio();
	void displayRecentTransactions();
	void addTransaction(StockMarket& dow, MMTransactions& mm);
	void displayCurrentValue();
	void displayOriginalvalue();
	void displayTotalGainLoss();
	void displayHoldings();
	double get_gainLoss();
	double get_currentValue();
	int get_key();
private:
	//map of every transaction listed in order from first to last
	std::map <int, StockTransactions> m_stockLedger;
	//map of holdings, stores the number of shares of every stock owned
	std::map <std::string, int> m_holdings;
	double m_totalGainLoss;
	double m_currentValue;
  int m_key;
	double m_originalValue;
	void incrementKey();
	void updateOriginalValue(StockTransactions newTrade);
};

#endif
