#include <iostream>
#include "StockMarket.h"

int main()
{
	FILE* infile;
	stock_market dow;
	int i = 0;

	infile = fopen("dow_jones.txt", "r");
	if (infile == NULL)
	{
		printf("failed to open dow_jones.txt\n");
		exit(1);
	}
	srand(static_cast <unsigned> (time(0)));
	init_stock_list(infile, &dow);

	display_stock_market(dow);
	update_stock_market(&dow);
	std::cout << "\n";
	display_stock_market(dow);

	return 0;
}