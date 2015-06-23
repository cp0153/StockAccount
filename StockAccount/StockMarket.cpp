#include "StockMarket.h"
#include <string.h>

void init_stock_list(FILE* infile, stock_market* dow)
{
	int i, stock_list_len;
	char temp_list[10];
	stock_list_len = 30;

	for (i = 0; i < stock_list_len; i++)
	{
		dow->prevPrice[i] = (double)rand() / (double)(RAND_MAX)* 100;
		dow->currentPrice[i] = dow->prevPrice[i];
		fgets(temp_list, 80, infile);
		temp_list[strcspn(temp_list, "\n")] = 0; //get rid of the newline charater fgets adds
		memcpy(dow->stockName[i], temp_list, 4); 
		dow->stockName[i][4] = '\0';
	}
	return;
}

void display_stock_market(stock_market dow)
{
	int i;
	printf("NUM\tSYM\tPrice(USD)\tPrev Price\t%% Change\n");
	for (i = 0; i < 30; i++)
	{
		printf("(%d)\t", i + 1);
		printf("%s\t", dow.stockName[i]);
		printf("%.2f", dow.currentPrice[i]);
		printf("\t\t");
		printf("%.2f", dow.prevPrice[i]);
		printf("\t\t");
		printf("%.2f\n", (dow.currentPrice[i] - dow.prevPrice[i]) / dow.prevPrice[i] * 100);
	}
	return;
}

void update_stock_market(stock_market *dow)
{
	int i, stock_list_len;
	double negative;
	double price_change;//change stock prices within 5%
	double percent_change = 0.05;
	double sum_index_prices = 0;
	double prev_index_prices = 0;
	stock_list_len = 30;

	for (i = 0; i < stock_list_len; i++) //update index
	{
		prev_index_prices = prev_index_prices + dow->currentPrice[i];
		price_change = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / percent_change));//((double)rand()) / ((double)(RAND_MAX / (5)) * 100);
		negative = ((double)(rand() % 2));
		if (negative == 0)
		{
			price_change = price_change + 1;
		}
		else
		{
			price_change = (price_change * -1) + 1;
		}
		dow->currentPrice[i] = dow->currentPrice[i] * price_change;
		sum_index_prices = sum_index_prices + dow->currentPrice[i];
	}
	return;
}