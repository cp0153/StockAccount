#ifndef TRANACTIONS_H
#define TRANSACTIONS_H
#include <string>
class Transactions
{
public:
	Transactions();
	virtual ~Transactions();
	void withdraw(double ammount);
	void deposit(double ammount);
	//check to make sure withdraw doesnt make account negative
	int compare(double balance, double amount); 
protected:
	std::string m_transactionDescription;
	// for money market add in variables and functions to compute the interest and add it to the 
	//account. I think we can just stright up inherit withdraw and deoposit, but not a big deal
	//if they are overridden 
};
#endif 