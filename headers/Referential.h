#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>
#include "Instrument.h"

template <typename InstrumentID, typename InstrumentType>
class Referential
{
	typedef std::string MnemoType;

public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentID, InstrumentType>> instrument);

private:
	std::unordered_map<MnemoType, std::shared_ptr<Instrument<InstrumentID, InstrumentType>>> instrumentsMapping_;
};

#include "Referential.hxx"

#endif