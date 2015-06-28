//#include <iostream>
//#include <map>
//#include "StockMarket.h"
//#include "MoneyMarketTransactions.h"
//#include "MoneyMarket.h"
//#include "StockTransactions.h"
//
//These are the tests for the various classes and methods
//int main()
//{
//	StockMarket test;
//	test.displayStockMarket();
//	std::cout << "\n";
//	test.updateStockMarket();
//	test.displayStockMarket();
//	std::cout << "\n";
//	test.updateStockMarket();
//	test.displayStockMarket();
//	std::cout << "\n";
//	test.updateStockMarket();
//	test.displayStockMarket();
//	MMTransactions acc1;
//	acc1.deposit(50000);
//
//	//std::map<int, Stocks> m;
//	//m.insert(std::pair<int, Stocks>(1, test.get_stock(5)));
//	//m.insert(std::pair<int, Stocks>(2, test.get_stock(8)));
//	////std::vector<int> v;
//	//for (std::map<int, Stocks>::iterator it = m.begin(); it != m.end(); ++it)
//	//{
//	//	std::cout << it->first << ": ";
//	//	std::cout << it->second.get_symbol() << "\n";
//	//}
//	//double amount = 5000000;
//	//MMTransactions acc1;
//	//if (acc1.deposit(amount))
//	//{
//	//	std::cout << "deposit of " << amount << " successful" << std::endl;
//	//}
//	//else
//	//{
//	//	std::cout << "deposit of " << amount << " failed" << std::endl;
//	//}
//	//int choice;
//	//do
//	//{
//	//	cout << "What Would You Like To Do?\n";
//	//	cout << "(1) Display Balance" << endl;
//	//	cout << "(2) Withdraw" << endl;
//	//	cout << "(3) Deposit" << endl;
//	//	cin >> choice;
//	//	switch (choice)
//	//	{
//	//	case 1:
//	//		acc1.get_balance();
//	//		break;
//	//	case 2:
//	//		acc1.withdraw(500);
//	//		if (acc1.withdraw(500) < 0)
//	//		{
//	//			cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << endl;
//	//		}
//	//		else if (acc1.withdraw(500)> acc1.get_balance())
//	//		{
//	//			cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << endl;
//	//		}
//	//		break;
//	//	case 3:
//	//		acc1.deposit(20);
//	//		if (acc1.deposit(50) < 0)
//	//		{
//	//			cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << endl;
//	//		}
//	//		break;
//	//	}
//	//	acc1.output();
//	//} while (choice == 1 || choice == 2 || choice == 3);
//
//	//tests of stock Transactions
//	StockTransactions testtrans;
//	if (testtrans.purchase(test.get_stock(5), acc1, 5))
//	{
//		std::cout << "purchase of " << test.get_stock(5).get_symbol() << " successful" << std::endl;
//		std::cout << "cost: " << test.get_stock(5).get_currentPrice() * testtrans.get_sharesOwned() << std::endl;
//	}
//	else
//	{
//		std::cout << "Fail" << std::endl;
//	}
//	test.updateStockMarket();
//	std::cout << "shares owned " << testtrans.get_sharesOwned() << std::endl;
//
//	if (testtrans.sell(test.get_stock(5), acc1, 3, 5))
//	{
//		std::cout << "sale of " << test.get_stock(5).get_symbol() << " successful ";
//		std::cout << "3 shares at " << test.get_stock(5).get_currentPrice() << std::endl;
//	}
//	else
//	{
//		std::cout << "Fail" << std::endl;
//	}
//	std::cout << "gained/lost " << testtrans.get_gains() << std::endl;
//	std::cout << "sold at " << testtrans.get_price() << std::endl;
//	std::cout << "shares owned " << testtrans.get_sharesOwned() << std::endl;
//	testtrans.displayTransaction();
//	return 0;
//}
