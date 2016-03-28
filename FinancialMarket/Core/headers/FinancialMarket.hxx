#pragma once
#ifndef FINANCIAL_MARKET_HXX_
#define FINANCIAL_MARKET_HXX_

#include "Way.h"
#include "FinancialMarket.h"
#include "InstrumentFactory.h"
#include <atomic>
#include <thread>
#include <iostream>

template <typename DerivedInstrument, typename OrderTraits, typename InstrumentTraits>
void FinancialMarket<DerivedInstrument, OrderTraits, InstrumentTraits>::LoadReferential()
{
	// unique id, name, isin, mnemo
    using TupleType = std::tuple<typename InstrumentTraits::InstrumentIDType, const std::string, const std::string, const std::string>;
	std::vector<TupleType> listing;

	listing.emplace_back(TupleType(0, "ACCOR", "FR0000120404", "AC"));
	listing.emplace_back(TupleType(1, "TOTAL", "FR0000120271", "FP"));

	for (const auto& tuple : listing)
	{
        matchingEngine_.CreateOrderBook(std::get<0>(tuple));
        referential_.AddInstrument(InstrumentFactory::BuildInstrument<DerivedInstrument>(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple), std::get<3>(tuple)));
	}

	//referential_.TestProtobuf();
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

    std::cout << "Type Quit to leave" << std::endl;
    while (run.load())
    {
        // main loop
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    run.store(false);
    cinThread.join();
}

#endif