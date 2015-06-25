#ifndef STOCK_TRANSACTIONS_H
#define STOCK_TRANSACTIONS_H

#include "Stocks.h"
#include "MoneyMarketTransactions.h"
#include "Portfolio.h"

class StockTransactions
{
public:
	StockTransactions();
	StockTransactions(StockTransactions& a_transaction);
	~StockTransactions();
	double get_purchasePrice();
	double get_salePrice();
	int get_sharesOwned();
	double get_gains();
	void set_purchasePrice(double price);
	void set_salePrice(double price);
	void set_sharesOwned(int shares);
	int purchase(Stocks symbol, MMTransactions mm, int shares);
	int sell(Stocks symbol, MMTransactions mm, int number_of_shares);

private:
	double m_purchasePrice;
	double m_salePrice;
	double m_gains;
	int m_sharesOwned;
};

#endif