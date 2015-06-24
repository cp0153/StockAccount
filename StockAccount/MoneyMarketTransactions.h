#ifndef MONEYMARKETTRANSACTIONS_H
#define MONEYMARKETTRANSACTIONS_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class MMTransactions
{
public:
	MMTransactions();
	~MMTransactions();
	void transfer(MMTransactions &another_account, double amount);
	double withdraw(double amount);
	int getWithdraws(int n_withdraws);
	void deposit(double amount);
	void output();
	double getBalance();
private:
	int n_withdraws;
	double balance;
	map < int, double > transaction;
};
#endif