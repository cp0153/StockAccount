#include <iostream>
#include <string>
#include "MoneyMarket.h"

using namespace std;

MoneyMarket::MoneyMarket()
{
	cout << "\nPlease Enter Your Name: ";
	cin >> name;
	balance = 0;
}
MoneyMarket::~MoneyMarket()
{}

void MoneyMarket::output()
{
	cout << "\nHello " << name << ", You have " << balance << " in your account" << endl;
}


