#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H

#include <cstdlib>
#include <stdio.h>
#include <ctime>

class StockMarket
{
public:
	StockMarket();
	~StockMarket();
	void displayStockMarket();
	void updateStockMarket();

private:
	char m_stockName[30][5];
	double m_prevPrice[30], m_currentPrice[30];
	FILE* m_infile;
};
#endif