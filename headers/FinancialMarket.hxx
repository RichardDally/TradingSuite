#ifndef FINANCIAL_MARKET_HXX_
#define FINANCIAL_MARKET_HXX_

#include "FinancialMarket.h"

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
void FinancialMarket<InstrumentType, InstrumentTraits, OrderID, Quantity, Price>::LoadReferential()
{
	// unique id, name, isin, mnemo
	typedef std::tuple<int, const std::string, const std::string, const std::string> TupleType;
	std::vector<TupleType> listing;

	listing.emplace_back(TupleType(0, "ACCOR", "FR0000120404", "AC"));
	listing.emplace_back(TupleType(1, "TOTAL", "FR0000120271", "FP"));

	for (const auto& tuple : listing)
	{
		std::shared_ptr<InstrumentType> instrument(new typename InstrumentType(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple), std::get<3>(tuple)));
		matchingEngine_.AddInstrument(instrument);
		referential_.AddInstrument(std::move(instrument));
	}
}

#endif