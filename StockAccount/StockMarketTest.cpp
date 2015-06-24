#include <iostream>
#include <map>
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

	std::map<int, char*> m;
	m.insert(std::pair<int, char*>(1, test.get_stock(5).get_symbol()));
	m.insert(std::pair<int, char*>(2, test.get_stock(8).get_symbol()));
	//std::vector<int> v;
	for (std::map<int, char*>::iterator it = m.begin(); it != m.end(); ++it)
	{
		std::cout << it->first << ": ";
		std::cout << it->second << "\n";
	}
	return 0;
}