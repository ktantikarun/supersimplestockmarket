/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#ifndef COMMONSTOCK_H
#define COMMONSTOCK_H

#include "Stock.h"

class CommonStock : virtual public Stock
{
public:
    CommonStock(string symbol_, double lastDividend_, double parValue_) : Stock(symbol_, lastDividend_, parValue_) { }
    virtual double getDividendYield(double price);
    virtual double getPERatio(double price);
	virtual string getSymbol();
};

#endif