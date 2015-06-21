#pragma once
#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include "Referential.h"
#include "MatchingEngine.h"

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
class FinancialMarket
{
public:
	void LoadReferential();
    void TestAddOrder();

private:
	Referential<InstrumentType, InstrumentTraits> referential_;
	MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits> matchingEngine_;
};

#include "FinancialMarket.hxx"

#endif