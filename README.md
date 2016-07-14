# StockAccount

Students: Chris Pearce, Jimmy Stein
Name of application: Brokerage account

Task: To make a simulation of a brokerage account with a money market account and portfolio that the user can buy and sell
stocks out of an account.

Objects: Brokerage Account is the class that creates all the other classes and runs the main menu, Stock market, money market
and money market transactions all have an aggregation relationship with brokerage account. Money market transactions are
inherited from money market. Stocks have an aggregation relationship with the stock market and the portfolio class. Stock
transactions are also a part of the portfolio class. For STL containers, money market transactions has a map that stores recent
transactions. Portfolio has two maps, one to store current holdings and another to store stock transactions. The stock market
has a vector that stores all the stocks listed on the market. 


