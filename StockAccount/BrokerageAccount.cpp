#include "BrokerageAccount.h"

brokerageAccount::brokerageAccount(){}
brokerageAccount::~brokerageAccount(){}

void brokerageAccount::mainMenu()
{
	MMTransactions acc1;
	acc1.deposit(10000);
	std::cout << acc1.get_name() << " $" << acc1.get_balance() << " has been deposited into your account.";
	std::cout << "\n";
	StockMarket dow;
	Portfolio portfolio;
	int main_choice;
	do{		
	std::cout << "What Would You Like To Do?" << std::endl;
	std::cout << "(1) Switch To Money Market\n";
	std::cout << "(2) Switch To Portfolio\n";
	std::cout << "(0) Exit\n";
	std::cin >> main_choice;
	while (main_choice < 0 || main_choice > 2)
	{
		std::cout << "invalid input, please enter a number between 1 and 3 or 0 to quit: ";
		std::cin >> main_choice;
	}
	
	switch (main_choice)
		{
		case 1:
			moneyMarketMenu(acc1, dow, portfolio);
			break;
		case 2:
			portfolioMenu(acc1, dow, portfolio);
			break;
		}
	} while (main_choice != 0 && acc1.get_balance() > 1);
	if (acc1.get_balance() <= 1)
	{
		std::cout << "You are out of money!\n";
	}
}

void brokerageAccount::moneyMarketMenu(MMTransactions& acc1, StockMarket& dow, Portfolio& portfolio)
{
	double amount;
	//MMTransactions acc1;
	//StockMarket Dow;
	int user_input;
	do
	{
		std::cout << "What Would You Like To Do?\n";
		std::cout << "(1) Display Balance" << std::endl;
		std::cout << "(2) Withdraw" << std::endl;
		std::cout << "(3) Deposit" << std::endl;
		std::cout << "(4) View recent transactions" << std::endl;
		std::cout << "(0) Go To Main Menu" << std::endl;
		std::cin >> user_input;
		while (user_input < 0 || user_input > 5)
		{
			std::cout << "invalid input, please enter a number between 1 and 3 or 0 to quit: ";
			std::cin >> user_input;
		}
		switch (user_input)
		{
		case 1:
			acc1.displayBalance();
			break;
		case 2:
			std::cout << "How Much?\n";
			std::cin >> amount;
			std::cout << "\nAttempting to withdraw $" << amount << "..." << std::endl;
			if (acc1.withdraw(amount))
			{
				std::cout << "withdraw of " << amount << " successful." << std::endl;
			}
			else
			{
				std::cout << "Error, withdrawal amount must be less than or equal to the balance." << std::endl;
				std::cout << "and greater than zero" << std::endl;
			}
			dow.updateStockMarket();
			break;
		case 3:
			std::cout << "How Much?\n";
			std::cin >> amount;
			std::cout << "\nAttempting to deposit $" << amount << "..." << std::endl;
			if (acc1.deposit(amount))
			{
				std::cout << "Deposit of " << amount << " successful" << std::endl;
			}
			else
			{
				std::cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << std::endl;
			}
			dow.updateStockMarket();
			break;
		case 4:
			acc1.displayRecentTransactions();
			break;
		}
	} while (user_input != 0 && acc1.get_balance() > 1);
	
}

void brokerageAccount::portfolioMenu(MMTransactions& acc1, StockMarket& dow, Portfolio& portfolio)
{
	//StockMarket Dow;
	int user_input;
	do
	{
		std::cout << "What Would You Like To Do?\n";
		std::cout << "(1) Display Portfolio\n";
		std::cout << "(2) View recent transactions\n";
		std::cout << "(3) make a trade\n";
		std::cout << "(0) Go To Main Menu\n";
		std::cin >> user_input;
		while (user_input < 0 || user_input > 4)
		{
			std::cout << "invalid input, please enter a number between 1 and 3 or 0 to quit: ";
			std::cin >> user_input;
		}
		switch (user_input)
		{
		case 1:
			portfolio.displayHoldings();
			break;
		case 2:
				portfolio.displayRecentTransactions();
			break;
		case 3:
			portfolio.addTransaction(dow, acc1);
			break;
		}
	} while (user_input != 0 && acc1.get_balance() > 1);
	
	
}
