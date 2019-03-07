/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#include "CommonStock.h"

double CommonStock::getDividendYield(double price)
{
    return lastDividend / price;
}

double CommonStock::getPERatio(double price)
{
    return  getDividendYield(price) == 0 ? 0 : price / getDividendYield(price);
}

string CommonStock::getSymbol()
{
	return symbol;
}