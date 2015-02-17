#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>
#include "Instrument.h"

template <typename InstrumentType, typename InstrumentTraits>
class Referential
{
	// Instrument traits
	typedef typename InstrumentTraits::InstrumentIDType InstrumentID;

public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>>&& instrument);

private:
	std::unordered_map<InstrumentID, std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>>> instrumentsMapping_;
};

#include "Referential.hxx"

#endif