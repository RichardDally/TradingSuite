#pragma once
#ifndef REFERENTIAL_HXX_
#define REFERENTIAL_HXX_

#include "Referential.h"

template <typename DerivedInstrument, typename InstrumentTraits>
void Referential<DerivedInstrument, InstrumentTraits>::AddInstrument(PointerType&& instrument)
{
	const auto it = instrumentsMapping_.find(instrument->GetInstrumentID());
	if (it != instrumentsMapping_.end())
	{
		// TODO: handle overwritting
		it->second = instrument;
	}
	else
	{
		instrumentsMapping_[instrument->GetInstrumentID()] = instrument;
	}
}

#endif