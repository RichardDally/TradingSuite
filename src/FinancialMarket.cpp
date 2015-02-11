#include "FinancialMarket.h"

FinancialMarket::FinancialMarket()
{
    ob.AddOrder(Way::BUY, 10, 100);
    ob.AddOrder(Way::BUY, 5, 99);
    ob.AddOrder(Way::BUY, 8, 98);

    ob.AddOrder(Way::SELL, 5, 101);
    ob.AddOrder(Way::SELL, 8, 102);
    ob.AddOrder(Way::SELL, 10, 103);

    ob.Dump();
}