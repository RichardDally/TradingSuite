#include <atomic>
#include <thread>
#include <iostream>
#include "OrderTraits.h"
#include "InstrumentTraits.h"
#include "StockInstrument.h"
#include "FinancialMarket.h"

void ReadCin(std::atomic<bool>& run)
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

int main()
{
    std::atomic<bool> run(true);
    std::thread cinThread(ReadCin, std::ref(run));

    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;
    using SimpleOrderIDType = int;
    using SimpleQuantityType = int;
    using SimplePriceType = int;
    using SimpleOrderTraits = OrderTraits<SimpleOrderIDType, SimpleQuantityType, SimplePriceType>;

    FinancialMarket<DerivedInstrumentType, SimpleOrderTraits, SimpleInstrumentTraits> fmarket;
	fmarket.LoadReferential();

    while (run.load())
    {
        // main loop
    }
    
    run.store(false);
    cinThread.join();

	return 0;
}
