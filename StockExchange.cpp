/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#include "StockExchange.h"

void StockExchange::registerStock(string stockSymbol, StockType type, double lastDividiend, double fixedDividend, double parValue)
{
	Stock *stock;
	if (type == COMMON)
	{
		stock = new CommonStock(stockSymbol, lastDividiend, parValue);
	}
	else if (type == PREFERRED)
	{
		stock = new PreferredStock(stockSymbol, lastDividiend, fixedDividend, parValue);
	}
	stocks.push_back(stock);
}

vector<Stock*>::iterator StockExchange::getStock(string stockSymbol)
{
	return std::find_if(stocks.begin(), stocks.end(), [&stockSymbol](Stock* stock) {
							return stock->getSymbol() == stockSymbol;
						});
}

bool StockExchange::findIfStockExists(string stockSymbol)
{
	return std::find_if(stocks.begin(), stocks.end(), [&stockSymbol](Stock* stock) {
							return stock->getSymbol() == stockSymbol;
						}) != stocks.end();
}

void StockExchange::addTrade(string stockSymbol, int quantityOfShares, TradeSignal indicator, double price)
{
	if(!findIfStockExists(stockSymbol))
		throw invalid_argument("Invalid Stock Symbol.");

	Trade trade(stockSymbol, quantityOfShares, indicator, price);
	trades.push_back(trade);
}

void StockExchange::getPastTrades(vector<Trade> &tradesByStock, string stockSymbol, Milliseconds time)
{
	if (!findIfStockExists(stockSymbol))
		throw invalid_argument("Invalid Stock Symbol.");

	Milliseconds current_timestamp = std::chrono::duration_cast<Milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	std::copy_if(trades.begin(), trades.end(), std::back_inserter(tradesByStock), [&stockSymbol, &current_timestamp, &time](Trade& trade) {
					return trade.getStockSymbol() == stockSymbol && current_timestamp - trade.getTimestamp() < time; // 15 Minutes = 900000 Milliseconds
				});
	double k = 0;
}

double StockExchange::calculateStockDividendYield(string stockSymbol, double price)
{
	if (!findIfStockExists(stockSymbol))
		throw invalid_argument("Invalid Stock Symbol.");

	vector<Stock*>::iterator p = getStock(stockSymbol);
	return (*p)->getDividendYield(price);
}

double StockExchange::calculateStockPERatio(string stockSymbol, double price)
{
	if (!findIfStockExists(stockSymbol))
		throw invalid_argument("Invalid Stock Symbol.");

	vector<Stock*>::iterator p = getStock(stockSymbol);
	return (*p)->getPERatio(price);
}

double StockExchange::computeVolumeWeightedStockPrice(string stockSymbol, Milliseconds time)
{
	if (!findIfStockExists(stockSymbol))
		throw invalid_argument("Invalid Stock Symbol.");

	vector<Trade> tradesByStock;
	getPastTrades(tradesByStock, stockSymbol, time);

	if (tradesByStock.size() == 0)
		return 0;

	double totalStockPrice = 0;
	double totalQuantity = 0;
	double volumeWeightedStockPrice = 0;
	for (Trade t : tradesByStock)
	{
		totalStockPrice += t.getPrice() * t.getQuantity();
		totalQuantity += t.getQuantity();
	}
	volumeWeightedStockPrice = totalStockPrice / totalQuantity;

	return volumeWeightedStockPrice;
}

double StockExchange::calculateGBCEAllShareIndex()
{
	double totalStockPrice = 1;
	for (Stock* a : stocks) {
		double stockPrice = computeVolumeWeightedStockPrice(a->getSymbol());
		totalStockPrice *= stockPrice != 0? stockPrice : 1.00;
	}
	totalStockPrice = pow(totalStockPrice, 1.0 / stocks.size());
	return totalStockPrice;
}