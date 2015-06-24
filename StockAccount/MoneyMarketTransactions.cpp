#include "MoneyMarketTransactions.h"

map<int, double>::iterator pos;
map<int, double>::iterator pos2;

MMTransactions::MMTransactions()
{
	balance = 0;
	n_withdraws = 0;
}
MMTransactions::~MMTransactions()
{}

void MMTransactions::transfer(MMTransactions &another_account, double amount)
{
	int i = 0;
	cout << "Attempting to transfer $" << amount << "..." << endl;
	withdraw(amount);
	if (amount > 0 && amount <= balance)
	{
		another_account.deposit(amount);
		cout << "\tTRANSFER COMPLETE" << endl;
		transaction.insert(pair<int, double>(i++, amount));
	}
	else if (amount < 0)
	{
		cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT TRANSFER" << endl;
	}
	else if (amount > balance)
	{
		cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT TRANSFER" << endl;
	}
}

double MMTransactions::withdraw(double amount)
{
	int i = 0;
	cout << "Attempting to withdraw $" << amount << "..." << endl;
	if (amount > 0 && amount <= balance)
	{
		if (n_withdraws > 1)
		{
			if (amount <= balance - 1.50)
			{
				balance -= (amount + 1.50);
				n_withdraws++;
			}
		}
		else
		{
			balance -= amount;
			n_withdraws++;
		}
		transaction.insert(pair<int, double>(i++, amount));
	}
	else if (amount < 0)
	{
		cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << endl;
		return 1;
	}
	else if (amount > balance)
	{
		cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << endl;
		return 1;
	}

	return balance;
}

int MMTransactions::getWithdraws(int n_withdraws)
{
	return n_withdraws;
}
void MMTransactions::deposit(double amount)
{
	int i = 0;
	cout << "Attempting to deposit $" << amount << "..." << endl;
	if (amount > 0)
	{
		balance += amount;
		cout << "\tDEPOSIT COMPLETE" << endl;
		transaction.insert(pair<int, double>(i++, amount));
	}
	else
	{
		cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << endl;
	}
}
void MMTransactions::output()
{
	cout << "You have " << n_withdraws << " withdraws" << endl;
	cout << "You have $" << getBalance() << " in your account" << endl;
	map<int, double>::iterator pos;
	for (pos = transaction.begin(); pos != transaction.end(); ++pos)
	{
		cout << "Key: " << pos->first << " value: ";
		/*map <int, double>::iterator it;
		for (it = pos->second.begin(); it != pos->second.end(); ++it)
		{*/
			//cout << *pos << " ";
	}
}
double MMTransactions::getBalance()
{
	return balance;
}