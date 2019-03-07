/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#include <iostream>
#include "Stock.h"
#include "Trade.h"
#include "CommonStock.h"
#include "PreferredStock.h"
#include "StockExchange.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	// Declare StockExchange 
	static StockExchange stockExchange;

	// Register stock to StockExchange 
	stockExchange.registerStock("TEA", COMMON, 0, 0, 100);
	stockExchange.registerStock("POP", COMMON, 8, 0, 100);
	stockExchange.registerStock("ALE", COMMON, 23, 0, 60);
	stockExchange.registerStock("GIN", PREFERRED, 8, 2, 100);
	stockExchange.registerStock("JOE", COMMON, 13, 0, 250);

	// Add trade to StockExchange
	stockExchange.addTrade("JOE", 20, BUY, 120);
	stockExchange.addTrade("JOE", 20, BUY, 110);
	stockExchange.addTrade("JOE", 20, SELL, 40);
	stockExchange.addTrade("GIN", 20, BUY, 120);
	stockExchange.addTrade("GIN", 20, BUY, 140);
	stockExchange.addTrade("ALE", 20, SELL, 120);

	// You can use the following statement to test the computeVolumeWeightedStockPrice
	//std::this_thread::sleep_for(Milliseconds(1000));

	// Compute Dividend Yield
	cout << stockExchange.calculateStockDividendYield("GIN", 100) << endl;

	// Compute PE Ratio
	cout << stockExchange.calculateStockDividendYield("GIN", 100) << endl;

	// Compute Volume-weighted Stock Price
	cout << stockExchange.computeVolumeWeightedStockPrice("JOE") << endl;

	// Compute the GBCE All Share Index
	cout << stockExchange.calculateGBCEAllShareIndex() << endl;

	system("pause");
	return 0;
}