#include "Stocks.h"
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <string.h>

Stocks::Stocks(){}

//Constructor takes  c-string and randomly generates a starting price for the stock
Stocks::Stocks(char symbol[5])
{
	const double LO = 25;
	const double HI = 300;

	m_prevPrice = LO + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (HI - LO)));
	m_currentPrice = m_prevPrice;
	memcpy(m_symbol, symbol, 4);
	m_symbol[4] = '\0';
}

Stocks::~Stocks(){}

void Stocks::updateStockPrice()
{
	double negative;
	double price_change;
	const double percent_change = 0.05;//percentage stock prices will change

	m_prevPrice = m_currentPrice;
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
	m_currentPrice = m_currentPrice * price_change;
}

void Stocks::displayStockInfo()
{
	printf("%s\t", get_symbol());
	printf("%.2f", get_prevPrice());
	printf("\t\t");
	printf("%.2f", get_currentPrice());
	printf("\t\t");
	printf("%.2f\n", (get_currentPrice() - get_prevPrice()) / get_prevPrice() * 100);
}

char* Stocks::get_symbol()
{
	return m_symbol;
}
double Stocks::get_prevPrice()
{
	return m_prevPrice;
}
double Stocks::get_currentPrice()
{
	return m_currentPrice;
}