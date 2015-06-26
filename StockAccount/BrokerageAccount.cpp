#include "BrokerageAccount.h"

brokerageAccount::brokerageAccount(){}
brokerageAccount::~brokerageAccount(){}

void brokerageAccount::mainMenu()
{
	MMTransactions acc1;
	StockMarket dow;
	Portfolio portfolio;
	int main_choice;
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
	do
	{
	switch (main_choice)
		{
		case 1:
			moneyMarketMenu(acc1, dow, portfolio);
			break;
		case 2:
			portfolioMenu(acc1, dow, portfolio);
			break;
		case 0:
			return;
		}
	} while (true);
	
}

bool brokerageAccount::moneyMarketMenu(MMTransactions& acc1, StockMarket& dow, Portfolio& portfolio)
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
			acc1.withdraw(amount);
			if (amount < 0)
			{
				std::cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << std::endl;
			}
			else if (amount > acc1.get_balance())
			{
				std::cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << std::endl;
			}
			dow.updateStockMarket();
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
			dow.updateStockMarket();
			break;
		case 4:
			acc1.displayRecentTransactions();
			break;
		case 0:
			return false;
		}

	} while (true);
	
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
			portfolio.displayCurrentValue();
			//portfolio.displayOriginalvalue();
			portfolio.displayTotalGainLoss();
			//std::cout << "display portfolio holdings here\n";
			break;
		case 2:
			//std::cout << "view recent transactions here, by calling portfolio.displayRecent";
				//std::cout << "Transactions()\n"; 
				portfolio.displayRecentTransactions();
			break;
		case 3:
			//std::cout << "call portfolio.addTransaction() here\n";
			//	Dow.buy();
			//	cout << "You Bought Stock " << Stock Name << " For " << amount;
			portfolio.addTransaction(dow, acc1);
			dow.updateStockMarket();
			break;
		case 0:
			return;
		}
	} while (true);
	
	
}
