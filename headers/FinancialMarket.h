#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include <memory>
#include <unordered_map>
#include "Instrument.h"
#include "OrderBook.h"
#include "Referential.h"

class FinancialMarket
{
public:
	FinancialMarket();

private:
	Referential referential_;
	OrderBook<int, int> ob;
};

#endif