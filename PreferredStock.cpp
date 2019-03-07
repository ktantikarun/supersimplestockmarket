/*
	Written by Krittaboon Tantikarun on 07/03/2019
*/

#include "PreferredStock.h"

double PreferredStock::getDividendYield(double price)
{
    return fixedDividend * parValue / price;
}

double PreferredStock::getPERatio(double price)
{
    return getDividendYield(price) == 0 ? 0 : price / getDividendYield(price);
}

string PreferredStock::getSymbol()
{
	return symbol;
}