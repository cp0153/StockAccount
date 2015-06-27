#include <iostream>
#include "StockTransactions.h"

StockTransactions::StockTransactions(): m_price(0), m_gains(0), 
	m_shares(0), m_symbol("Missing"), m_transactionType(transactionType::NA){}

StockTransactions::~StockTransactions(){}

double StockTransactions::get_price()
{
	return m_price;
}

int StockTransactions::get_sharesOwned()
{
	return m_shares;
}

double StockTransactions::get_gains()
{
	return m_gains;
}

std::string StockTransactions::get_symbol()
{
	return m_symbol;
}
transactionType StockTransactions::get_transactionType()
{
	return m_transactionType;
}

void StockTransactions::set_price(double price)
{
	m_price = price;
}

void StockTransactions::set_shares(int shares)
{
	m_shares = shares;
}

bool StockTransactions::purchase(Stocks symbol, MMTransactions& mm, int shares)
{
	double cost = symbol.get_currentPrice() * shares;
	if (mm.withdraw(cost))
	{
		set_price(cost);
		set_shares(shares);
		set_symbol(symbol.get_symbol());
		m_transactionType = transactionType::PURCHASE;
		return true;
	}
	else
	{
		return false;
	}
}

bool StockTransactions::sell(Stocks symbol, MMTransactions& mm, int shares, int shares_owned)
{
	if (shares > get_sharesOwned())
	{
		return false;
	}
	else
	{
		set_price(symbol.get_currentPrice() * shares);
		set_shares(get_sharesOwned() - shares);
		mm.deposit(get_price());
		m_gains = get_price() - get_price();
		set_symbol(symbol.get_symbol());
		if (get_gains() > 0)
		{
			mm.deposit(get_gains());
		}
		m_transactionType = transactionType::SALE;
		return true;
	}
}

void StockTransactions::set_symbol(char symbol[5])
{
	m_symbol = symbol;
}

std::string StockTransactions::displayTransactionType()
{
	if (m_transactionType == transactionType::PURCHASE)
	{
		return "Purchase";
	}
	else if (m_transactionType == transactionType::SALE)
	{
		return "Sale\t";
	}
	else
	{
		return "----\t";
	}
}
void StockTransactions::displayTransaction()
{
	std::cout << m_symbol << "\t" << displayTransactionType() << "\t" << m_shares << "\t"
		<< m_price << "\t" << m_price * m_shares << std::endl;
}