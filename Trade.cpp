#include "Trade.h"

using namespace std;

Milliseconds Trade::getTimestamp()
{
    return timestamp;
}

double Trade::getQuantity()
{
    return quantityOfShares;
}

double Trade::getPrice()
{
    return price;
}

string Trade::getStockSymbol()
{
    return stockSymbol;
}