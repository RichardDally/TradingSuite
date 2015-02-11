#include <tuple>
#include "StockInstrument.h"
#include "Referential.h"

Referential::Referential()
{
    // name, isin, mnemo
	typedef std::tuple<const std::string, const std::string, const std::string> TupleType;
	std::vector<TupleType> listing;

    listing.emplace_back(TupleType("ACCOR", "FR0000120404", "AC"));
	listing.emplace_back(TupleType("TOTAL", "FR0000120271", "FP"));
    
	
	for (const auto& tuple : listing)
	{
		std::shared_ptr<Instrument> instrument(new StockInstrument(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple)));
		AddInstrument(std::move(instrument));
	}
}

bool Referential::AddInstrument(std::shared_ptr<Instrument> instrument)
{
    const auto it = instrumentsByMnemo_.find(instrument->GetMnemo());
    if (it != instrumentsByMnemo_.end())
    {
        // Overwritting existing instrument...
        it->second = std::move(instrument);
    }
    else
    {
        instrumentsByMnemo_[instrument->GetMnemo()] = std::move(instrument);
    }

    return true;
}