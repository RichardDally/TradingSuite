#include <tuple>
#include "StockInstrument.h"
#include "Referential.h"

Referential::Referential()
{
}

void Referential::AddInstrument(std::shared_ptr<Instrument> instrument)
{
	const auto it = instrumentsMapping_.find(instrument->GetUniqueIdentifier());
	if (it != instrumentsMapping_.end())
    {
		// TODO: handle overwritting
        it->second = std::move(instrument);
    }
    else
    {
		instrumentsMapping_[instrument->GetUniqueIdentifier()] = std::move(instrument);
    }
}