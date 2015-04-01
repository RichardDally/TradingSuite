#pragma once
#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>
#include "Instrument.h"
#include "InstrumentMessage.pb.h"

template <typename InstrumentType, typename InstrumentTraits>
class Referential
{
	// Instrument traits
	typedef typename InstrumentTraits::InstrumentIDType InstrumentID;

public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>>&& instrument);

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

	std::weak_ptr<Instrument<InstrumentType, InstrumentTraits>> GetInstrument(const InstrumentID& id)
	{
		std::weak_ptr<Instrument<InstrumentType, InstrumentTraits>> instr(nullptr);

		const auto it = instrumentsMapping_.find(id);
		if (it != instrumentsMapping_.end())
		{
			// Build weak ptr from shared ptr
			instr = it->second;
		}

		return instr;
	}

private:
	std::unordered_map<InstrumentID, std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>>> instrumentsMapping_;
};

#include "Referential.hxx"

#endif