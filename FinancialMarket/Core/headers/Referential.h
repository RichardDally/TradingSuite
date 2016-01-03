#pragma once
#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>
#include "StockInstrument.h"
#include "GenericInstrument.h"

template <typename DerivedInstrument, typename InstrumentTraits>
class Referential
{
protected:
	// Instrument traits
    using InstrumentIDType = typename InstrumentTraits::InstrumentIDType;

public:
	// Aliases
    using InstrumentType = GenericInstrument<DerivedInstrument, InstrumentTraits>;
    using PointerType = std::shared_ptr<InstrumentType>;
    using WeakPointerType = std::weak_ptr<InstrumentType>;
    using InstrumentContainer = std::unordered_map<InstrumentIDType, PointerType>;

    void AddInstrument(PointerType&& instrument);

    WeakPointerType GetInstrument(const InstrumentIDType& id)
	{
        WeakPointerType instr;

		const auto it = instrumentsMapping_.find(id);
		if (it != instrumentsMapping_.end())
		{
			// Build weak ptr from shared ptr
			instr = it->second;
		}

		return instr;
	}

protected:
    InstrumentContainer instrumentsMapping_;
};

#include "Referential.hxx"

#endif
