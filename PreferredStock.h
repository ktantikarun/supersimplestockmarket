/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#ifndef PREFERREDSTOCK_H
#define PREFERREDSTOCK_H

#include "Stock.h"

class PreferredStock : virtual public Stock
{
private:
    double fixedDividend;

public:
    PreferredStock(string symbol_, double lastDividend_, double fixedDividend_, double parValue_) : Stock(symbol_, lastDividend_, parValue_), fixedDividend(fixedDividend_) { }
    virtual double getDividendYield(double price);
    virtual double getPERatio(double price);
	virtual string getSymbol();
};

#endif
