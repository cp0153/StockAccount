#include "BrokerageAccount.h"
#include "MoneyMarketTransactions.h"
#include "MoneyMarket.h"
#include "StockMarket.h"
#include "Stocks.h"

brokerageAccount::brokerageAccount(){}
brokerageAccount::~brokerageAccount(){}

void brokerageAccount::mainMenu()
{
	int main_choice;
	std::cout << "What Would You Like To Do?" << std::endl;
	std::cout << "(1) Switch To Money Market\n";
	std::cout << "(2) Switch To Portfolio\n";
	std::cout << "(3) Exit\n";
	std::cin >> main_choice;
	switch (main_choice)
	{
	case 1:
		moneyMarketMenu();
		break;
	case 2:
		portfolioMenu();
		break;
	case 3:
		exit(1);
		break;
	}
}

void brokerageAccount::moneyMarketMenu()
{
	double amount;
	MMTransactions acc1;
	StockMarket Dow;
	int choice;
	do
	{
		std::cout << "What Would You Like To Do?\n";
		std::cout << "(1) Display Balance" << std::endl;
		std::cout << "(2) Withdraw" << std::endl;
		std::cout << "(3) Deposit" << std::endl;
		std::cout << "(4) Go To Main Menu" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			acc1.get_balance();
			break;
		case 2:
			std::cout << "How Much?\n";
			std::cin >> amount;
			std::cout << "\nAttempting to withdraw $" << amount << "..." << std::endl;
			acc1.withdraw(amount);
			if (amount < 0)
			{
				std::cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << std::endl;
			}
			else if (amount > acc1.get_balance())
			{
				std::cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << std::endl;
			}
			//Dow.updateStockMarket();
			break;
		case 3:
			std::cout << "How Much?\n";
			std::cin >> amount;
			std::cout << "\nAttempting to deposit $" << amount << "..." << std::endl;
			acc1.deposit(amount);
			if (amount < 0)
			{
				std::cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << std::endl;
			}
			//Dow.updateStockMarket();
			break;
		case 4:
			mainMenu();
			break;
		}
		acc1.output();
	} while (choice == 1 || choice == 2 || choice == 3);
	
}

void brokerageAccount::portfolioMenu()
{
	StockMarket Dow;
	int stockChoice;
	do
	{
		std::cout << "What Would You Like To Do?\n";
		std::cout << "(1) Display Portfolio\n";
		std::cout << "(2) View Transaction\n";
		std::cout << "(3) Buy\n";
		std::cout << "(4) Sell\n";
		std::cout << "(5) Go To Main Menu\n";
		std::cin >> stockChoice;
		switch (stockChoice)
		{
		case 1:
			//	Dow.display_portfolio();
			//std::cout << "1 works\n";// test worked
			break;
		case 2:
			//std::cout << "2 works\n"; //test worked
			//	Dow.view_transactions();
			break;
		case 3:
			//std::cout << "3 works\n";// test worked
			//	Dow.buy();
			//	cout << "You Bought Stock " << Stock Name << " For " << amount;
			//	Dow.updateStockMarket();
			break;
		case 4:
			//  std::cout << "4 works\n";//test worked
			//	Dow.sell();
			//	cout << "You Sold Stock " << Stock Name << " For " << amount;
			//	Dow.updateStockMarket();
			break;
		case 5:
			mainMenu();//test worked
			break;
		}
	} while (stockChoice == 1 || stockChoice == 2 || stockChoice == 3 || stockChoice == 4);
	
	
}
