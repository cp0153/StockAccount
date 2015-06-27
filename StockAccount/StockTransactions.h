#ifndef STOCK_TRANSACTIONS_H
#define STOCK_TRANSACTIONS_H

#include <string>
#include "Stocks.h"
#include "MoneyMarketTransactions.h"

enum class transactionType {PURCHASE, SALE, NA};

class StockTransactions
{
public:
	StockTransactions();
	~StockTransactions();
	double get_price();
	int get_sharesOwned();
	double get_gains();
	std::string get_symbol();
	transactionType get_transactionType();
	void set_price(double price);
	void set_shares(int shares);
	void set_symbol(char symbol[5]);
	bool purchase(Stocks symbol, MMTransactions& mm, int shares);
	bool sell(Stocks symbol, MMTransactions& mm, int shares, int shares_owned);
	std::string displayTransactionType();
	void displayTransaction();

private:
	double m_price;
	double m_gains;
	int m_shares;
	std::string m_symbol;
	transactionType m_transactionType;
};

#endif
