#include "MoneyMarketTransactions.h"

MMTransactions::MMTransactions() : MoneyMarket()
{
	m_balance = 0;
	m_key = 0;
}

MMTransactions::MMTransactions(std::string name, double balance): MoneyMarket(name, balance), m_key(0){}

MMTransactions::~MMTransactions()
{}

bool MMTransactions::withdraw(double amount)
{
	if (amount > 0 && amount <= m_balance)
	{
		transaction.insert(std::pair<int, double>(++m_key, amount));
		m_balance -= amount;
		return true;
	}
	else if (amount < 0)
	{
		return false;
	}
	else if (amount > m_balance)
	{
		return false;
	}
	
}

bool MMTransactions::deposit(double amount)
{
	if (amount > 0)
	{
		m_balance += amount;
		transaction.insert(std::pair<int, double>(++m_key, amount));
		return true;
	}
	else
	{
		return false;
	}
}

void MMTransactions::displayRecentTransactions()
{
	std::cout << "\nYou have $" << get_balance() << " in your account" << std::endl;
	std::cout << "\n";
	std::map<int, double>::iterator pos;
	for (pos = transaction.begin(); pos != transaction.end(); ++pos)
	{
		std::cout << "Transaction #:" << pos->first << "\tvalue: $" << pos->second << std::endl;
	}
	std::cout << std::endl;
}

double MMTransactions::get_balance()
{
	return m_balance;
}

void MMTransactions::displayBalance()
{
	std::cout << "\nYou have $" << get_balance() << " in your account" << std::endl;
}
