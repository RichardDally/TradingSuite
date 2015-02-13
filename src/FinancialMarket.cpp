#include "StockInstrument.h"
#include "FinancialMarket.h"

FinancialMarket::FinancialMarket()
{
}

void FinancialMarket::LoadReferential()
{
	// name, isin, mnemo
	typedef std::tuple<const std::string, const std::string, const std::string> TupleType;
	std::vector<TupleType> listing;

	listing.emplace_back(TupleType("ACCOR", "FR0000120404", "AC"));
	listing.emplace_back(TupleType("TOTAL", "FR0000120271", "FP"));

	for (const auto& tuple : listing)
	{
		std::shared_ptr<Instrument> instrument(new StockInstrument(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
		matchingEngine_.AddInstrument(instrument);
		referential_.AddInstrument(std::move(instrument));
	}
}