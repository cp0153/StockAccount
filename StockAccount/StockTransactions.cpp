#include <iostream>
#include "StockTransactions.h"


StockTransactions::StockTransactions(): m_purchasePrice(0), m_salePrice(0), m_gains(0), 
	m_sharesOwned(0){}

StockTransactions::StockTransactions(StockTransactions& a_transaction)
{
	m_purchasePrice = a_transaction.m_purchasePrice;
	m_salePrice = a_transaction.m_salePrice;
	m_gains = a_transaction.m_gains;
	m_sharesOwned = a_transaction.m_sharesOwned;
}

StockTransactions::~StockTransactions(){}

double StockTransactions::get_purchasePrice()
{
	return m_purchasePrice;
}

double StockTransactions::get_salePrice()
{
	return m_salePrice;
}
int StockTransactions::get_sharesOwned()
{
	return m_sharesOwned;
}

double StockTransactions::get_gains()
{
	return m_gains;
}

string StockTransactions::get_symbol()
{
	return m_symbol;
}

void StockTransactions::set_purchasePrice(double price)
{
	m_purchasePrice = price;
}

void StockTransactions::set_salePrice(double price)
{
	m_salePrice = price;
}

void StockTransactions::set_sharesOwned(int shares)
{
	m_sharesOwned = shares;
}

bool StockTransactions::purchase(Stocks symbol, MMTransactions mm, int shares)
{
	double cost = symbol.get_currentPrice() * shares;
	if (mm.withdraw(cost))
	{
		set_purchasePrice(cost);
		set_sharesOwned(shares);
		set_symbol(symbol.get_symbol());
		return true;
	}
	else
	{
		return false;
	}
}

bool StockTransactions::sell(Stocks symbol, MMTransactions mm, int number_of_shares)
{
	if (number_of_shares > get_sharesOwned())
	{
		return false;
	}
	else
	{
		set_salePrice(symbol.get_currentPrice() * number_of_shares);
		set_sharesOwned(get_sharesOwned() - number_of_shares);
		mm.deposit(get_salePrice());
		m_gains = get_salePrice() - get_purchasePrice();
		set_symbol(symbol.get_symbol());
		return true;
	}
}

void StockTransactions::set_symbol(char symbol[5])
{
	m_symbol = symbol;
}

