#ifndef REFERENTIAL_HXX_
#define REFERENTIAL_HXX_

#include <tuple>
#include "StockInstrument.h"
#include "Referential.h"

template <typename InstrumentID, typename InstrumentType>
void Referential<InstrumentID, InstrumentType>::AddInstrument(std::shared_ptr<Instrument<InstrumentID, InstrumentType>> instrument)
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

#endif