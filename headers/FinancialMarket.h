#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include "Referential.h"
#include "MatchingEngine.h"

template <typename InstrumentID, typename InstrumentType, typename OrderID, typename Quantity, typename Price>
class FinancialMarket
{
public:
	void LoadReferential();

private:
	Referential<InstrumentID, InstrumentType> referential_;
	MatchingEngine<InstrumentID, InstrumentType, OrderID, Quantity, Price> matchingEngine_;
};

#endif