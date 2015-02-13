#ifndef STOCK_INSTRUMENT_H_
#define STOCK_INSTRUMENT_H_

#include "Instrument.h"

class StockInstrument : public Instrument
{
public:
	explicit StockInstrument(const std::string& name, const std::string& isin, const std::string& mnemo)
		: name_(name), isin_(isin), mnemo_(mnemo)
	{
	}

	virtual ~StockInstrument() override
	{ 
	}

	virtual const std::string& GetUniqueIdentifier() const override
	{
		// NOTE: Simple implementation, StockInstrument mnemo must be unique.
		return mnemo_;
	}

	virtual const std::string& GetName() const override
	{
		return name_;
	}

	virtual const std::string& GetISIN() const override
	{
		return isin_;
	}

	virtual const std::string& GetMnemo() const override
	{
		return mnemo_;
	}

protected:
	const std::string name_;
	const std::string isin_;
	const std::string mnemo_;
};

#endif