#include <iostream>
#include "StockMarket.h"
#include "MoneyMarket.h"
#include "MoneyMarketTransactions.h"

int main()
{
	StockMarket test;
	test.displayStockMarket();
	std::cout << "\n";
	test.updateStockMarket();
	test.displayStockMarket();
	std::cout << "\n";
	test.updateStockMarket();
	test.displayStockMarket();
	std::cout << "\n";
	test.updateStockMarket();
	test.displayStockMarket();


	//Testing for main
	MoneyMarket acct1;
	acct1.output();

	MMTransactions acct2;
	acct2.output();
	acct2.deposit(600);
	acct2.output();
	return 0;
}