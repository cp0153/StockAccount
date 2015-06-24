#include <iostream>
#include "StockTransactions.h"
#include "Stocks.h"

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
int StockTransactions::purchase(Stocks symbol, int number_of_shares)
{
	
}

int StockTransactions::sell(Stocks symbol, int number_of_shares)
{

}

