#ifndef BROKERAGE_ACCOUNT_H
#define BROKERAGE_ACCOUNT_H
#include "MoneyMarket.h"
#include "Portfolio.h"

class BrokerageAccount
{
public:
	BrokerageAccount();
	~BrokerageAccount();
	void mainMenu();
	void MoneyMarketMenu();
	void StockAccountMenu();
private:
	MoneyMarket m_money_market;
	Portfolio m_Portfolio;

};

#endif