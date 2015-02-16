#include <iostream>
#include "InstrumentTraits.h"
#include "StockInstrument.h"
#include "FinancialMarket.h"

int main()
{
	InstrumentTraits<int> simple;

	FinancialMarket<StockInstrument<decltype(simple)>, decltype(simple), int, int, int> fmarket;
	fmarket.LoadReferential();

	int dummy;
	std::cin >> dummy;

	return 0;
}