#ifndef REFERENTIAL_HXX_
#define REFERENTIAL_HXX_

#include "Referential.h"

template <typename InstrumentType, typename Traits>
void Referential<InstrumentType, Traits>::AddInstrument(std::shared_ptr<Instrument<InstrumentType, Traits>> instrument)
{
	const auto it = instrumentsMapping_.find(instrument->GetInstrumentID());
	if (it != instrumentsMapping_.end())
	{
		// TODO: handle overwritting
		it->second = std::move(instrument);
	}
	else
	{
		instrumentsMapping_[instrument->GetInstrumentID()] = std::move(instrument);
	}
}

#endif