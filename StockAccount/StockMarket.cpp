#include "StockMarket.h"
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

//reads in ticker symbols from a file, randomly generates prices that will be matched
//to the ticker symbols and stored in a class for the stock account to use.
//Has a function that updates all of prices within a range of -5% to +5%
StockMarket::StockMarket()
{
	int stock_list_len;
	char temp_list[10];
	stock_list_len = 30;
	srand(time(NULL));

	m_infile = fopen("dow_jones.txt", "r");
	if (m_infile == NULL)
	{
		printf("failed to open dow_jones.txt\n");
		exit(1);
	}

	for (int i = 0; i < stock_list_len; i++)
	{
		fgets(temp_list, 80, m_infile);
		temp_list[strcspn(temp_list, "\n")] = 0; //get rid of the newline charater fgets adds
		Market.push_back(Stocks(temp_list));
	}
	fclose(m_infile);
}

StockMarket::~StockMarket(){}

//outputs a table of every stock price, the price from the previous time period, and the percentage
//change between time periods
void StockMarket::displayStockMarket()
{
	printf("NUM\tSYM\tPrev Price(USD)\tPrice(USD)\tChange(%%)\n");
	for (int i = 0; i < 30; i++)
	{
		printf("(%d)\t", i + 1);
		Market[i].displayStockInfo();
	}
}

//used to mark the end of a time period, market prices will be randomly updated to increase
//or decrease 5%
void StockMarket::updateStockMarket()
{
	int stock_list_len = 30;
	
	for (int i = 0; i < stock_list_len; i++) //update index
	{
		Market[i].updateStockPrice();
	}
}

Stocks StockMarket::get_stock(int selection)
{
	return Market[selection];
}
