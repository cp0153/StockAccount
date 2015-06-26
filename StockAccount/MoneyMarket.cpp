#include <iostream>
#include <string>
#include "MoneyMarket.h"

MoneyMarket::MoneyMarket()
{
	std::cout << "Please Enter Your Name: ";
	std::cin >> m_name;
	m_balance = 0;
	std::cout << "\nHello " << m_name << ", You have " << m_balance << " in your account" << std::endl;
}
MoneyMarket::~MoneyMarket()
{}



