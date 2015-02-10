#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include <memory>
#include <unordered_map>
#include "Instrument.h"
#include "OrderBook.h"

class FinancialMarket
{
public:
	FinancialMarket();
	bool AddInstrument(std::unique_ptr<Instrument> instrument);

private:
	// Instruments indexed by ISIN
	std::unordered_map<std::string, std::unique_ptr<Instrument>> referential_;
	OrderBook<int, int> ob;
};

#endif