#include "StockMarket.h"
#include <string.h>

//reads in ticker symbols from a file, randomly generates prices that will be matched
//to the ticker symbols and stored in a class for the stock account to use.
//Has a helper function that updates all of prices within a range of -5% to +5%
StockMarket::StockMarket()
{
	int i, stock_list_len;
	char temp_list[10];
	stock_list_len = 30;
	const double LO = 25;
	const double HI = 300;

	m_infile = fopen("dow_jones.txt", "r");
	if (m_infile == NULL)
	{
		printf("failed to open dow_jones.txt\n");
		exit(1);
	}

	for (i = 0; i < stock_list_len; i++)
	{
		m_prevPrice[i] = LO + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (HI - LO)));
		m_currentPrice[i] = m_prevPrice[i];
		fgets(temp_list, 80, m_infile);
		temp_list[strcspn(temp_list, "\n")] = 0; //get rid of the newline charater fgets adds
		memcpy(m_stockName[i], temp_list, 4); 
		m_stockName[i][4] = '\0';
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
		printf("%s\t", m_stockName[i]);
		printf("%.2f", m_prevPrice[i]);
		printf("\t\t");
		printf("%.2f", m_currentPrice[i]);
		printf("\t\t");
		printf("%.2f\n", (m_currentPrice[i] - m_prevPrice[i]) / m_prevPrice[i] * 100);
	}
}

//used to mark the end of a time period, market prices will be randomly updated to increase
//or decrease 5%
void StockMarket::updateStockMarket()
{
	int i, stock_list_len;
	double negative;
	double price_change;
	const double percent_change = 0.05;//percentage stock prices will change
	double sum_index_prices = 0;
	stock_list_len = 30;
	
	for (i = 0; i < stock_list_len; i++) //update index
	{
		m_prevPrice[i] = m_currentPrice[i];
		//change stock prices within 5%
		price_change = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / percent_change));
		negative = ((double)(rand() % 2));
		if (negative == 0)
		{
			price_change = price_change + 1;
		}
		else
		{
			price_change = (price_change * -1) + 1;
		}
		m_currentPrice[i] = m_currentPrice[i] * price_change;
		sum_index_prices = sum_index_prices + m_currentPrice[i];
	}
}
