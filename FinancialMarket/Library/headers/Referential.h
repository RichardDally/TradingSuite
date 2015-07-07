#pragma once
#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>
#include "StockInstrument.h"
#include "GenericInstrument.h"
#include "InstrumentMessage.pb.h"

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

	void TestProtobuf()
	{
		GOOGLE_PROTOBUF_VERIFY_VERSION;

		PB::ReferentialMessage referentialWrite;
		for (const auto& pair : instrumentsMapping_)
		{
			auto instr = referentialWrite.add_instrument();
			instr->set_id(pair.second->GetInstrumentID());
			instr->set_isin(pair.second->GetISIN());
			instr->set_mnemo(pair.second->GetMnemo());
			instr->set_name(pair.second->GetName());
		}

		std::string buffer;
		referentialWrite.SerializeToString(&buffer);

		PB::ReferentialMessage referentialRead;
		referentialRead.ParseFromString(buffer);

		for (int i = 0; i < referentialRead.instrument_size(); ++i)
		{
			StockInstrument<InstrumentTraits> instr(referentialRead.instrument(i).id(), referentialRead.instrument(i).name(), referentialRead.instrument(i).isin(), referentialRead.instrument(i).mnemo());
			std::cout << "Id: " << instr.GetInstrumentID() << std::endl;
			std::cout << "Name: " << instr.GetName() << std::endl;
			std::cout << "ISIN: " << instr.GetISIN() << std::endl;
			std::cout << "Mnemo: " << instr.GetMnemo() << std::endl;
		}
	}

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
