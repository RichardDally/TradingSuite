#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>
#include "Instrument.h"

template <typename InstrumentType, typename Traits>
class Referential
{
public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentType, Traits>> instrument);

private:
	std::unordered_map<typename Traits::InstrumentIDType, std::shared_ptr<Instrument<InstrumentType, Traits>>> instrumentsMapping_;
};

#include "Referential.hxx"

#endif