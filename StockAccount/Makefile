# AWESOME MAKEFILE FOR THE STOCK MARKET PROGRAM 30000
# Flags to save on typing all this shit out
# g++ is the linux C++ compiler, CFLAGS are helpful flags to use.
CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic

# Make the executable
all:	StockMarketTest

# Executable - link the object files
# Linkage flags go at the end if you use any API / frameworks EX Boost.
StockMarketTest: main.o BrokerageAccount.o MoneyMarket.o Portfolio.o StockMarket.o Stocks.o StockTransactions.o
	$(CC) main.o BrokerageAccount.o MoneyMarket.o Portfolio.o StockMarket.o Stocks.o StockTransactions.o -o StockMarketTest

# Create the object files
# First is the "main" object file.
# Compile flags go at the end. Use them for checking for errors.
main.o: main.cpp
	$(CC) -c main.cpp BrokerageAccount.h $(CFLAGS)

# Use -c for COMPILE. You compile your source code into OBJECT FILES
BrokerageAccount.o: BrokerageAccount.cpp BrokerageAccount.h
	$(CC) -c BrokerageAccount.cpp BrokerageAccount.h MoneyMarket.h Portfolio.h StockMarket.h $(CFLAGS)

# Gotta compile all the source code m8.
# Also, the reason for the .cpp / .hpp stuff is so stuff gets recompiled
# when the source code changes.
MoneyMarket.o: MoneyMarket.cpp MoneyMarket.h
	$(CC) -c MoneyMarket.cpp MoneyMarket.h $(CFLAGS)

Portfolio.o: Portfolio.cpp Portfolio.h
	$(CC) -c Portfolio.cpp Portfolio.h $(CFLAGS)

StockMarket.o: StockMarket.cpp StockMarket.h
	$(CC) -c StockMarket.cpp StockMarket.h $(CFLAGS)

Stocks.o: Stocks.cpp Stocks.h
	$(CC) -c Stocks.cpp Stocks.h $(CFLAGS)

StockTransactions.o: StockTransactions.cpp StockTransactions.h
	$(CC) -c StockTransactions.cpp StockTransactions.h $(CFLAGS)

# Cleanup object files / executable. Use "make clean" to run this part.
# Useful for making sure your code compiles from the start, and not
# because some random object file wasn't recompiled.
clean:
	rm *.o
	#rm *.gch
	rm StockMarketTest
