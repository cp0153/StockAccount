#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H

#include <cstdlib>
#include <stdio.h>
#include <ctime>

typedef struct stock_list{
	char stockName[30][5];
	double prevPrice[30], currentPrice[30];
}stock_market;

void init_stock_list(FILE* infile, stock_market* dow);
void display_stock_market(stock_market dow);
void update_stock_market(stock_market *dow);

#endif