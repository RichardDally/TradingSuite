#ifndef STOCK_INSTRUMENT_H_
#define STOCK_INSTRUMENT_H_

#include "Instrument.h"

class StockInstrument : public Instrument<int, StockInstrument>
{
public:
	explicit StockInstrument(const std::string& name, const std::string& isin, const std::string& mnemo)
		: name_(name), isin_(isin), mnemo_(mnemo)
	{
	}

	const std::string& GetUniqueIdentifier() const
	{
		// NOTE: Simple implementation, StockInstrument mnemo must be unique.
		return mnemo_;
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
	const std::string name_;
	const std::string isin_;
	const std::string mnemo_;
};

#endif