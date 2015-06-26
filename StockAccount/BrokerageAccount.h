#ifndef BROKERAGE_ACCOUNT_H
#define BROKERAGE_ACCOUNT_H
#include "MoneyMarketTransactions.h"
#include "MoneyMarket.h"
#include "StockMarket.h"
#include "Stocks.h"
#include "Portfolio.h"
#include "StockTransactions.h"

class brokerageAccount
{
public:
	brokerageAccount();
	~brokerageAccount();
	void mainMenu();
	bool moneyMarketMenu(MMTransactions& acc1, StockMarket& dow, Portfolio& portfolio);
	void portfolioMenu(MMTransactions& acc1, StockMarket& dow, Portfolio& portfolio);
//private:
	//MoneyMarket m_money_market;
	//Portfolio m_Portfolio;

};

#endif