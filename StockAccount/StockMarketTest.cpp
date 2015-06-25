#include <iostream>
#include <map>
#include "StockMarket.h"
#include "MoneyMarketTransactions.h"
#include "MoneyMarket.h"

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

	//MMTransactions acc1;
	//
	//int choice;
	//do
	//{
	//	cout << "What Would You Like To Do?\n";
	//	cout << "(1) Display Balance" << endl;
	//	cout << "(2) Withdraw" << endl;
	//	cout << "(3) Deposit" << endl;
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 1:
	//		acc1.get_balance();
	//		break;
	//	case 2:
	//		acc1.withdraw();
	//		if (acc1.withdraw() < 0)
	//		{
	//			cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << endl;
	//		}
	//		else if (acc1.withdraw()> acc1.get_balance())
	//		{
	//			cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << endl;
	//		}
	//		break;
	//	case 3:
	//		acc1.deposit();
	//		if (acc1.deposit() < 0)
	//		{
	//			cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << endl;
	//		}
	//		break;
	//	}
	//	acc1.output();
	//} while (choice == 1 || choice == 2 || choice == 3);
	
	return 0;
}