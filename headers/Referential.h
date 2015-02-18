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

	std::weak_ptr<Instrument<InstrumentType, InstrumentTraits>> GetInstrument(const InstrumentID& id)
	{
		std::weak_ptr<Instrument<InstrumentType, InstrumentTraits>> instr(nullptr);

		const auto it = instrumentsMapping_.find(id);
		if (it != instrumentsMapping_.end())
		{
			instr = it->second;
		}

		return instr;
	}

private:
	std::unordered_map<InstrumentID, std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>>> instrumentsMapping_;
};

#include "Referential.hxx"

#endif