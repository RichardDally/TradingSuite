#include "OrderTraits.h"
#include "InstrumentTraits.h"
#include "StockInstrument.h"
#include "FinancialMarket.h"

int main()
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;
    using SimpleOrderIDType = int;
    using SimpleQuantityType = int;
    using SimplePriceType = int;
    using SimpleOrderTraits = OrderTraits<SimpleOrderIDType, SimpleQuantityType, SimplePriceType>;

    FinancialMarket<DerivedInstrumentType, SimpleOrderTraits, SimpleInstrumentTraits> fmarket(42000);
	fmarket.LoadReferential();
    fmarket.Run();

	return 0;
}
