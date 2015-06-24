#ifndef STOCK_TRANSACTIONS_H
#define STOCK_TRANSACTIONS_H

#include "Stocks.h"
#include "MoneyMarketTransactions.h"
#include "Portfolio.h"

class StockTransactions
{
public:
	StockTransactions();
	~StockTransactions();
	double get_purchasePrice();
	double get_salePrice();
	int get_numberOfShares();
	double set_purchasePrice(double price);
	double set_salePrice(double price);
	int set_numberOfShares(int shares);
	int purchase(Stocks symbol, MMTransactions mm, int number_of_shares);
	int sell(Stocks symbol, MMTransactions mm, Portfolio portfolio, int number_of_shares);

private:
	double m_purchasePrice;
	double m_salePrice;
	double m_Gains;
	int m_numberOfShares;
};

#endif