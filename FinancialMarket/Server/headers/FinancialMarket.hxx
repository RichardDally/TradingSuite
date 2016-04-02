#pragma once
#ifndef FINANCIAL_MARKET_HXX_
#define FINANCIAL_MARKET_HXX_

#include "Way.h"
#include "FinancialMarket.h"
#include "InstrumentFactory.h"
#include "ReferentialSerialization.h"
#include <atomic>
#include <thread>
#include <iostream>

template <typename DerivedInstrument, typename OrderTraits, typename InstrumentTraits>
FinancialMarket<DerivedInstrument, OrderTraits, InstrumentTraits>::FinancialMarket(const short port)
    : referentialServer_(port)
{
}

template <typename DerivedInstrument, typename OrderTraits, typename InstrumentTraits>
void FinancialMarket<DerivedInstrument, OrderTraits, InstrumentTraits>::LoadReferential()
{
    std::vector<DerivedInstrument> instruments;

    // TODO: change to read in database referential
    instruments.emplace_back(0, "ACCOR", "FR0000120404", "AC");
    instruments.emplace_back(1, "TOTAL", "FR0000120271", "FP");

	for (const auto& instrument : instruments)
	{
        matchingEngine_.CreateOrderBook(instrument.GetInstrumentID());
        referential_.AddInstrument(InstrumentFactory::BuildInstrument<DerivedInstrument>(instrument.GetInstrumentID(), instrument.GetName(), instrument.GetISIN(), instrument.GetMnemo()));
	}

    auto encodedReferential = EncodeReferential(instruments);
    if (std::get<1>(encodedReferential))
    {
        referentialServer_.SetReferential(std::move(std::get<0>(encodedReferential)));
    }
    else
    {
        // TODO: log an error
    }
}

template<typename DerivedInstrument, typename OrderTraits, typename InstrumentTraits>
inline void FinancialMarket<DerivedInstrument, OrderTraits, InstrumentTraits>::Run()
{
    std::atomic<bool> run(true);
    std::thread cinThread([](std::atomic<bool>& run)
    {
        std::string buffer;

        while (run.load())
        {
            std::cin >> buffer;
            if (buffer == "Quit")
            {
                run.store(false);
            }
        }
    }
    , std::ref(run));

    //referentialServer_.Start();

    std::cout << "Type Quit to leave" << std::endl;
    while (run.load())
    {
        // main loop
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    //referentialServer_.Stop();

    run.store(false);
    cinThread.join();
}

#endif