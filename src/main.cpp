#include <iostream>
#include "OrderTraits.h"
#include "InstrumentTraits.h"
#include "StockInstrument.h"
#include "FinancialMarket.h"

int main()
{
	InstrumentTraits<int> simpleInstrumentTraits;
	OrderTraits<int, int, int> simpleOrderTraits;
	typedef StockInstrument<decltype(simpleInstrumentTraits)> InstrumentType;

	FinancialMarket<InstrumentType, decltype(simpleOrderTraits), decltype(simpleInstrumentTraits)> fmarket;
	fmarket.LoadReferential();

	int dummy;
	std::cin >> dummy;

	return 0;
}