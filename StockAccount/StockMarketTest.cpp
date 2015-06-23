#include <iostream>
#include <map>
#include "StockMarket.h"

int main()
{
	/*StockMarket test;
	test.displayStockMarket();
	std::cout << "\n";
	test.updateStockMarket();
	test.displayStockMarket();
	std::cout << "\n";
	test.updateStockMarket();
	test.displayStockMarket();
	std::cout << "\n";
	test.updateStockMarket();
	test.displayStockMarket();*/

	std::map<int, int> m;
	m.insert(std::pair<int, int>(1, 100));
	m.insert(std::pair<int, int>(2, 200));
	//std::vector<int> v;
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		//v.push_back(it->first);
		std::cout << it->first << "\n";
	}
	return 0;
}