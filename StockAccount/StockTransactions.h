#ifndef STOCK_TRANSACTIONS_H
#define STOCK_TRANSACTIONS_H

#include <string>
#include "Stocks.h"
#include "MoneyMarketTransactions.h"

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
	string get_symbol();
	void set_purchasePrice(double price);
	void set_salePrice(double price);
	void set_sharesOwned(int shares);
	void set_symbol(char symbol[5]);
	bool purchase(Stocks symbol, MMTransactions mm, int shares);
	bool sell(Stocks symbol, MMTransactions mm, int number_of_shares);
	void displayTransaction();

private:
	double m_purchasePrice;
	double m_salePrice;
	double m_gains;
	int m_sharesOwned;
	string m_symbol;
};

#endif