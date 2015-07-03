//#include <iostream>
//#include <map>
//#include <iomanip>
//#include "StockMarket.h"
//#include "MoneyMarketTransactions.h"
//#include "MoneyMarket.h"
//#include "StockTransactions.h"
//#include "Portfolio.h"
////These are the tests for the various classes and methods
//int main()
//{
//	//tests of stock market and stocks
//	std::cout << std::fixed;
//	std::cout << std::setprecision(2);
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
//	
//
//	//tests of Money market and Money Market transactions
//	std::string name = "Chris";
//	MMTransactions testMM(name, 100);
//	std::cout << "The owners name is " << testMM.get_name() << std::endl;
//	double amount = 5000000;
//	if (testMM.deposit(amount))
//	{
//		std::cout << "deposit of " << amount << " successful" << std::endl;
//	}
//	else
//	{
//		std::cout << "deposit of " << amount << " failed" << std::endl;
//	}
//	testMM.displayBalance();
//
//	testMM.withdraw(500);
//	if (testMM.withdraw(500))
//	{
//		std::cout << "Sucessful withdrawal." << std::endl;
//	}
//	else
//	{
//		std::cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << std::endl;
//	}
//	testMM.deposit(20);
//
//	if (testMM.deposit(50))
//	{
//		std::cout << "Deposit successful" << std::endl;
//	}
//	else
//	{
//		std::cout << "Deposit of 50 failed" << std::endl;
//	}
//
//	if (testMM.deposit(-50))
//	{
//		std::cout << "Deposit successful" << std::endl;
//	}
//	else
//	{
//		std::cout << "Deposit failed" << std::endl;
//	}
//
//	testMM.displayRecentTransactions();
//
//	//tests of stock Transactions
//	StockTransactions testtrans;
//	if (testtrans.purchase(test.get_stock(5), testMM, 5))
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
//	if (testtrans.sell(test.get_stock(5), testMM, 3, 5))
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
//
//	//tests of portfolio
//	Portfolio portfolio_test;
//	portfolio_test.displayCurrentValue();
//	portfolio_test.addTransaction(test, testMM);
//	portfolio_test.displayCurrentValue();
//	portfolio_test.displayHoldings();
//	std::cout << "The current values of m_key should be 2 is " << portfolio_test.get_key();
//	std::cout << "\n";
//
//	return 0;
//}
