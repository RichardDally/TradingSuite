#ifndef STOCK_INSTRUMENT_H_
#define STOCK_INSTRUMENT_H_

#include "Instrument.h"
#include "InstrumentTraits.h"

template <typename InstrumentTraits>
class StockInstrument : public Instrument <StockInstrument<InstrumentTraits>, InstrumentTraits>
{
	typedef typename InstrumentTraits::InstrumentIDType InstrumentIDType;

public:
	explicit StockInstrument(const InstrumentIDType id, const std::string& name, const std::string& isin, const std::string& mnemo)
		:  id_(id), name_(name), isin_(isin), mnemo_(mnemo)
	{
	}

	const InstrumentIDType& GetInstrumentID() const
	{
		// NOTE: Simple implementation, instrument id must be unique.
		return id_;
	}

	const std::string& GetName() const
	{
		return name_;
	}

	const std::string& GetISIN() const
	{
		return isin_;
	}

	const std::string& GetMnemo() const
	{
		return mnemo_;
	}

protected:
	const InstrumentIDType id_;
	const std::string name_;
	const std::string isin_;
	const std::string mnemo_;
};

#endif