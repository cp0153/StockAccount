#include <iostream>
#include <string>
#include "MoneyMarket.h"

using namespace std;

MoneyMarket::MoneyMarket()
{
	cout << "\nPlease Enter Your Name: ";
	cin >> m_name;
	m_balance = 0;
	cout << "\nHello " << m_name << ", You have " << m_balance << " in your account" << endl;
}
MoneyMarket::~MoneyMarket()
{}



