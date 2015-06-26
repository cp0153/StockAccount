#include "Portfolio.h"

Portfolio::Portfolio(): m_gainLoss(0), m_currentValue(0), m_key(0), m_originalValue(0){}

Portfolio::~Portfolio(){}

void Portfolio::displayRecentTransactions()
{
	
	//for (std::map<int, StockTransactions>::iterator it = m_stockLedger.begin();
	//	it != m_stockLedger.end(); ++it)
	//		{
	//			std::cout << it->first << ": ";
	//			std::cout << it->second << "\n";
	//		}
}

void Portfolio::addTransaction(StockTransactions newTrade)
{
	m_key++;
	m_stockLedger.insert(std::pair<int, StockTransactions>(m_key, newTrade));
}

void Portfolio::displayCurrentValue()
{

}

void Portfolio::displayGainLoss()
{

}

double Portfolio::get_gainLoss()
{

}

double Portfolio::get_NetValue()
{

}

int Portfolio::get_key()
{
	return m_key;
}

void Portfolio::incrementKey()
{
	m_key++;
}

void Portfolio::updateOriginalValue(StockTransactions newTrade)
{
	m_originalValue += newTrade.get_purchasePrice;
}