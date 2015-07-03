#include <iostream>
#include "MoneyMarket.h"
MoneyMarket::MoneyMarket()
{
	std::cout << "Please Enter Your Name: ";
	std::cin >> m_name;
	m_balance = 0;
	std::cout << "\nHello " << m_name << ", You have $" << m_balance << " in your account" << std::endl;
}

MoneyMarket::MoneyMarket(std::string name, double balance)
{
	m_name = name;
	m_balance = balance;
}

MoneyMarket::~MoneyMarket(){}

std::string MoneyMarket::get_name()
{
	return m_name;
}
