#include "BrokerageAccount.h"
#include "MoneyMarketTransactions.h"
#include "StockMarket.h"

brokerageAccount::brokerageAccount(){}
brokerageAccount::~brokerageAccount(){}

void brokerageAccount::mainMenu()
{
	int main_choice;
	cout << "What Would You Like To Do?" << endl;
	cout << "(1) Switch To Money Market\n";
	cout << "(2) Switch To Portfolio\n";
	cin >> main_choice;
	switch (main_choice)
	{
	case 1:
		moneyMarketMenu();
		break;
	case 2:
		portfolioMenu();
		break;
	}
}

void brokerageAccount::moneyMarketMenu()
{
	MMTransactions acc1;
	int choice;
	cout << "What Would You Like To Do?\n";
	cout << "(1) Display Balance" << endl;
	cout << "(2) Withdraw" << endl;
	cout << "(3) Deposit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		acc1.get_balance();
		break;
	case 2:
		acc1.withdraw();
		if (acc1.withdraw() < 0)
		{
			cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << endl;
		}
		else if (acc1.withdraw()> acc1.get_balance())
		{
			cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << endl;
		}
		updateStockMarket();
		break;
	case 3:
		acc1.deposit();
		if (acc1.deposit() < 0)
		{
			cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << endl;
		}
		updateStockMarket();
		break;
	}
	acc1.output();*/
}

void brokerageAccount::portfolioMenu()
{
	//int stockChoice;
	//cout << "What Would You Like To Do?\n";
	//cout << "(1) Display Portfolio\n";
	//cout << "(2) View Transaction\n";
	//cout << "(3) Buy\n"
	//cout << "(4) sell\n"
	//cin >> stockChoice;
	//switch (stockChoice)
	//{
	//case 1:
	//	display_portfolio();
	//	break;
	//case 2:
	//	//view_transactions();
	//	break;
	//case 3:
	//	buy();
	//	updateStockMarket();
	//	break;
	//case 4:
	//	sell();
	//	updateStockMarket();
	//	break;
	
}
