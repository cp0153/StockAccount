#include "Portfolio.h"

Portfolio::Portfolio(): m_totalGainLoss(0), m_currentValue(0), m_key(0), m_originalValue(0){}

Portfolio::~Portfolio(){}

void Portfolio::displayRecentTransactions()
{
	std::cout << "Symbol\tTrans Type\tShares\tPrice\tAmount" << std::endl;
	for (std::map<int, StockTransactions>::iterator it = m_stockLedger.begin();
	it != m_stockLedger.end(); ++it)
		{
			std::cout << it->first << ": ";
			it->second.displayTransaction();
		}
}

void Portfolio::addTransaction(StockMarket dow, MMTransactions mm)
{
	int user_input, stock_choice, shares;
	StockTransactions newTrade;

	do
	{
		std::cout << "What Would You Like To Do?\n";
		std::cout << "(1) Display Market\n";
		std::cout << "(2) Buy\n";
		std::cout << "(3) Sell\n";
		std::cout << "(0) Return to portfolio Menu\n";
		std::cin >> user_input;
		while (user_input < 0 || user_input > 3)
		{
			std::cout << "invalid input, please enter a number between 1 and 3 or 0 to quit: ";
			std::cin >> user_input;
		}
		switch (user_input)
		{
		case 1:
			dow.displayStockMarket();
			break;
		case 2:
			std::cout << "What would you like to purchase? Pick a number between 1 and 30: ";
			std::cin >> stock_choice;
			while (stock_choice < 0 || stock_choice > 30)
			{
				std::cout << "invalid input, please enter a number between 1 and 30: ";
				std::cin >> stock_choice;
			}
			std::cout << dow.get_stock(stock_choice).get_symbol() << " costs ";
			std::cout << dow.get_stock(stock_choice).get_currentPrice() << " per share.\n";
			std::cout << "How many shares would you like to purchase? please enter a positive number: ";
			std::cin >> shares;
			while (shares < 0 || shares > mm.get_balance())
			{
				std::cout << "invalid input, number is negative or insufficent funds: ";
				std::cin >> shares;
			}
			
			incrementKey();
			if (newTrade.purchase(dow.get_stock(stock_choice).get_symbol(), mm, shares))
			{
				m_stockLedger.insert(std::pair<int, StockTransactions>(m_key, newTrade));
				m_holdings.insert(std::pair<std::string, int>(dow.get_stock(stock_choice).get_symbol(), shares));
				updateOriginalValue(newTrade);
			}
			else
			{
				std::cout << "purchase failed, please try again" << std::endl;		
			}
			break;
		case 3:
			std::cout << "What would you like to sell? Pick a number between 1 and 30: ";
			std::cin >> stock_choice;
			while (stock_choice < 0 || stock_choice > 30)
			{
				std::cout << "invalid input, please enter a number between 1 and 30: ";
				std::cin >> stock_choice;
			}
			std::cout << dow.get_stock(stock_choice).get_symbol() << " is currently trading at ";
			std::cout << dow.get_stock(stock_choice).get_currentPrice() << " per share.\n";
			std::cout << "How many shares would you like to sell?" << "You currently own" << m_holdings[dow.get_stock(stock_choice).get_symbol()] << "shares\n";
			std::cout << " enter a positive number less than or equal to the amount of shares you currently own: ";
			std::cin >> shares;
			while (shares < 0 || shares > m_holdings[dow.get_stock(stock_choice).get_symbol()])
			{
				std::cout << "invalid input, number is negative or exceeds the number of shares you own: ";
				std::cin >> shares;
			}

			incrementKey();
			if (newTrade.sell(dow.get_stock(stock_choice).get_symbol(), mm, shares, m_holdings[dow.get_stock(stock_choice).get_symbol()]))
			{
				m_stockLedger.insert(std::pair<int, StockTransactions>(m_key, newTrade));
				m_holdings.insert(std::pair<std::string, int>(dow.get_stock(stock_choice).get_symbol(), shares));
				updateOriginalValue(newTrade);
			}
			else
			{
				std::cout << "Sale failed, please try again" << std::endl;
			}
			break;	
		}
	} while (user_input != 0);

}

void Portfolio::displayCurrentValue()
{
	std::cout << m_currentValue << std::endl;
}

void Portfolio::displayTotalGainLoss()
{
	std::cout << m_totalGainLoss << std::endl;
}

double Portfolio::get_gainLoss()
{
	return m_totalGainLoss;
}

double Portfolio::get_currentValue()
{
	return m_currentValue;
}

int Portfolio::get_key()
{
	return m_key;
}

void Portfolio::incrementKey()
{
	m_key++;
}

void Portfolio::updateOriginalValue(StockTransactions newTrade)
{
	m_originalValue += newTrade.get_price();
}

