# Super Simple Stock Market
------
##### Requirements
1. Provide working source code that will :-
a. For a given stock,
    1. Given any price as input, calculate the dividend yield
    2. Given any price as input, calculate the P/E Ratio
    3. Record a trade, with timestamp, quantity of shares, buy or sell indicator and traded price
    4. Calculate Volume Weighted Stock Price based on trades in past 15 minutes
2. Calculate the GBCE All Share Index using the geometric mean of prices for all stocks

##### Development
1. Source code in this project is written in C++ and follows C++11 standard. 
2. Developed and tested in Microsoft Visual Studio 15 2017 Win64.

##### Assumptionsss
1. In this program, I assume that price of each stock used to calculate the GBCE All Share Index comes from the volume-weighted stock price on trades in past 15 minutes.
2. Since there are no requirements for the precision scale and the boundary of  stock price, I decide to use Double to store the value and the output of calculated price is not scaled.
3. It is assumed that all the input value is in a correct formats, e.g. stock price is a positive number.

##### Usage
* Example of function calling is provided in the main class.
* the StockExchange class is a service for performing all tasks provided in this project.ห

------
This work is produced by Krittaboon Tantikarun as part of application to JP Morgan Chase & Co.

