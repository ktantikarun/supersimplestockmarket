/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#ifndef STOCKEXCHAGE_H
#define STOCKEXCHAGE_H

#include <string.h>
#include <algorithm>
#include <vector>
#include "PreferredStock.h"
#include "CommonStock.h"
#include "Trade.h"

class StockExchange
{
private:
	vector<Trade> trades;
	vector<Stock*> stocks;
	bool findIfStockExists(string stockSymbol);
	void getPastTrades(vector<Trade> &tradesByStock, string stockSymbol, Milliseconds time);

public:
	StockExchange() { }
	void registerStock(string stockSymbol, StockType type, double lastDividiend, double fixedDividend, double parValue);
	vector<Stock*>::iterator getStock(string stockSymbol);
	void addTrade(string stockSymbol, int quantityOfShares, TradeSignal indicator, double price);
	double calculateStockDividendYield(string stockSymbol, double price);
	double calculateStockPERatio(string stockSymbol, double price);
	double computeVolumeWeightedStockPrice(string stockSymbol, Milliseconds time = Milliseconds(900000));
	double calculateGBCEAllShareIndex();
};

#endif