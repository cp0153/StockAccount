#ifndef STOCK_TRANSACTIONS_H
#define STOCK_TRANSACTIONS_H

class StockTransactions
{
public:
	StockTransactions();
	~StockTransactions();
	double get_purchasePrice();
	int get_numberOfShares();
	int purchase(Stocks symbol, int number_of_shares);
	int sell(Stocks symbol, int number_of_shares);

private:
	double m_purchasePrice;
	int m_numberOfShares;
};

#endif