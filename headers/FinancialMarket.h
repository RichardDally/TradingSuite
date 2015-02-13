#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include <string>
#include <unordered_map>
#include "Instrument.h"
#include "OrderBook.h"
#include "Referential.h"

class FinancialMarket
{
public:
	FinancialMarket();

	void LoadReferential();

private:
	typedef OrderBook<int, int> OrderBookType;
	Referential referential_;

	// Key: mnemo
	// Value: order book
	std::unordered_map<std::string, OrderBookType> orderBooks_;
};

#endif