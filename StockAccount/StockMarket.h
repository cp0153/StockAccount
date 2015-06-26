#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H
#include <vector>
#include "Stocks.h"
#include <stdio.h>

class StockMarket
{
public:
	StockMarket();
	~StockMarket();
	void displayStockMarket();
	void updateStockMarket();
	Stocks get_stock(int selection);
	

private:
	std::vector <Stocks> Market;
	FILE* m_infile;
};
#endif