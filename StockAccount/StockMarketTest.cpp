#include <iostream>
#include "StockMarket.h"

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
	return 0;
}