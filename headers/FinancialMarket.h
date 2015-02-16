#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include "Referential.h"
#include "MatchingEngine.h"

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
class FinancialMarket
{
public:
	void LoadReferential();

private:
	Referential<InstrumentType, InstrumentTraits> referential_;
	MatchingEngine<InstrumentType, InstrumentTraits, OrderID, Quantity, Price> matchingEngine_;
};

#include "FinancialMarket.hxx"

#endif