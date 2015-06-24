#include <iostream>
#include "StockTransactions.h"


StockTransactions::StockTransactions(){}
StockTransactions::~StockTransactions(){}

double StockTransactions::get_purchasePrice()
{
	return m_purchasePrice;
}

int StockTransactions::get_numberOfShares()
{
	return m_numberOfShares;
}

double StockTransactions::set_purchasePrice(double price){}

double StockTransactions::set_salePrice(double price){}

int StockTransactions::set_numberOfShares(int shares){}

int StockTransactions::purchase(Stocks symbol, MMTransactions mm, int number_of_shares)
{
	double cost = symbol.get_currentPrice * number_of_shares;
	if (mm.withdraw)
	{
		set_purchasePrice(cost);
		set_numberOfShares(number_of_shares);
		return 1;
	}
	else
	{
		return 0;
	}
}

int StockTransactions::sell(Stocks symbol, MMTransactions mm, Portfolio portfolio, int number_of_shares)
{
	if (number_of_shares > portfolio.get_numShares())
	{
		return 0;
	}
	else
	{
		set_salePrice(symbol.get_currentPrice * number_of_shares);
		m_numberOfShares -= number_of_shares;
		mm.deposit(m_salePrice);
	}

}

