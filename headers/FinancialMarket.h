#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include "Referential.h"
#include "MatchingEngine.h"

class FinancialMarket
{
public:
	FinancialMarket();
	void LoadReferential();

private:
	Referential referential_;
	MatchingEngine matchingEngine_;
};

#endif