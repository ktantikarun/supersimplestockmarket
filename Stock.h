/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#ifndef STOCK_H
#define STOCK_H

#include <string.h>
#include <vector>

using namespace std;

enum StockType { COMMON, PREFERRED };

class Stock 
{
    protected:
        string symbol;
        double lastDividend;
        double parValue;
        double latestPrice;

    public:
		Stock() {}
        Stock(string symbol_, double lastDividend_, double parValue_) : symbol(symbol_), lastDividend(lastDividend_), parValue(parValue_) { }
        virtual double getPERatio(double price) = 0;
        virtual double getDividendYield(double price) = 0;
		virtual string getSymbol() = 0;
};

#endif