#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include "Referential.h"
#include "MatchingEngine.h"

template <typename InstrumentType, typename InstrumentTraits, typename OrderTraits>
class FinancialMarket
{
public:
	void LoadReferential();

private:
	Referential<InstrumentType, InstrumentTraits> referential_;
	MatchingEngine<InstrumentType, InstrumentTraits, OrderTraits> matchingEngine_;
};

#include "FinancialMarket.hxx"

#endif