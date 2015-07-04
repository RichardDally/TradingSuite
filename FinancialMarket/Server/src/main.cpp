#include <iostream>
#include "OrderTraits.h"
#include "InstrumentTraits.h"
#include "StockInstrument.h"
#include "FinancialMarket.h"

int main()
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using InstrumentType = StockInstrument<SimpleInstrumentTraits>;
    using SimpleOrderIDType = int;
    using SimpleOrderTraits = OrderTraits<SimpleOrderIDType, int, int>;

    FinancialMarket<InstrumentType, SimpleOrderTraits, SimpleInstrumentTraits> fmarket;
	fmarket.LoadReferential();

	int dummy;
	std::cin >> dummy;

	return 0;
}