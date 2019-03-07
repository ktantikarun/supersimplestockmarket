/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#ifndef TRADE_H
#define TRADE_H

#include "Stock.h"
#include <chrono>

using namespace std;
typedef std::chrono::milliseconds Milliseconds;

enum TradeSignal { BUY, SELL };

class Trade
{
private:
    string stockSymbol;
	Milliseconds timestamp;
    int quantityOfShares;
    TradeSignal indicator;
    double price;

public:
	Trade()
	{}
    Trade(string stockSymbol_, int quantityOfShares_, TradeSignal indicator_, double price_)
            : stockSymbol(stockSymbol_), quantityOfShares(quantityOfShares_), indicator(indicator_), price(price_)
    {
        timestamp = std::chrono::duration_cast<Milliseconds>( std::chrono::system_clock::now().time_since_epoch() );
    }
	Milliseconds getTimestamp();
    double getQuantity();
    double getPrice();
    string getStockSymbol();
};

#endif