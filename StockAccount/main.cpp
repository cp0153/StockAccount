#include "BrokerageAccount.h"
#include <iomanip>
int main()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	brokerageAccount brokerage_account;
	brokerage_account.mainMenu();

	return 0;
}
