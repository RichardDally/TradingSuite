#pragma once
#ifndef FINANCIAL_MARKET_H_
#define FINANCIAL_MARKET_H_

#include "Referential.h"
#include "MatchingEngine.h"
#include "ReferentialServer.h"

template <typename DerivedInstrument, typename OrderTraits, typename InstrumentTraits>
class FinancialMarket
{
public:
    FinancialMarket(const unsigned short port);
	void LoadReferential();
    void Run();

private:
    boost::asio::io_service ioService_;
    ReferentialServer referentialServer_;
    Referential<DerivedInstrument, InstrumentTraits> referential_;
    MatchingEngine<DerivedInstrument, OrderTraits, InstrumentTraits> matchingEngine_;
};

#include "FinancialMarket.hxx"

#endif