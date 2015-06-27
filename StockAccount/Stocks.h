#ifndef STOCKS_H
#define STOCKS_H

class Stocks
{
public:
	Stocks();
	Stocks(char symbol[5]);
	~Stocks();
	void updateStockPrice();
	void displayStockInfo();
	char* get_symbol();
	double get_prevPrice();
	double get_currentPrice();
private:
	char m_symbol[5];
	double m_prevPrice, m_currentPrice;
};

#endif
