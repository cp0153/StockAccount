#ifndef BROKERAGE_ACCOUNT_H
#define BROKERAGE_ACCOUNT_H
#include "MoneyMarket.h"
#include "Portfolio.h"

class brokerageAccount
{
public:
	brokerageAccount();
	~brokerageAccount();
	void mainMenu();
	void moneyMarketMenu();
	void stockAccountMenu();
private:
	//MoneyMarket m_money_market;
	//Portfolio m_Portfolio;

};

#endif