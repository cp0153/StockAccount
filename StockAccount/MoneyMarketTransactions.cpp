#include "MoneyMarketTransactions.h"

MMTransactions::MMTransactions() : MoneyMarket()
{
	m_balance = 0;
}
MMTransactions::~MMTransactions()
{}

int MMTransactions::withdraw(double amount)
{
	//cout << "\nAttempting to withdraw $" << amount << "..." << endl;
	if (amount > 0 && amount <= m_balance)
	{
		//cout << "\tWITHDRAW COMPLETE" << endl;
		transaction.insert(pair<int, double>(++m_key, amount));
		m_balance -= amount;
	}
	else if (amount < 0)
	{
		//cout << "Error, withdrawal amount must be greater than 0.\n\tCANNOT WITHDRAW." << endl;
		return 0;
	}
	else if (amount > m_balance)
	{
		//cout << "Error, withdrawal amount must be less than or equal to the balance.\n\tCANNOT WITHDRAW: INSUFFICIENT FUNDS" << endl;
		return 0;
	}
	return 1;
}

int MMTransactions::deposit(double amount)
{
	//cout << "\nAttempting to deposit $" << amount << "..." << endl;
	if (amount > 0)
	{
		m_balance += amount;
		//cout << "\tDEPOSIT COMPLETE" << endl;
		transaction.insert(pair<int, double>(++m_key, amount));
		return 1;
	}
	else
	{
		//cout << "Error, deposit amount must be non-negative.\n\tCANNOT DEPOSIT" << endl;
		return 0;
	}
}
void MMTransactions::output()
{
	cout << "\nYou have $" << get_balance() << " in your account" << endl;
	map<int, double>::iterator pos;
	for (pos = transaction.begin(); pos != transaction.end(); ++pos)
	{
		cout << "Key: " << pos->first << " value: $" << pos->second << endl;
	}
}
double MMTransactions::get_balance()
{
	return m_balance;
}
