#pragma once
#ifndef STOCK_INSTRUMENT_H_
#define STOCK_INSTRUMENT_H_

#include "GenericInstrument.h"
#include "InstrumentTraits.h"

template <typename InstrumentTraits>
class StockInstrument : public GenericInstrument<StockInstrument<InstrumentTraits>, InstrumentTraits>
{
	typedef typename InstrumentTraits::InstrumentIDType InstrumentIDType;

public:
	explicit StockInstrument(const InstrumentIDType id, const std::string& name, const std::string& isin, const std::string& mnemo)
		:  id_(id), name_(name), isin_(isin), mnemo_(mnemo)
	{
	}

	~StockInstrument() = default;
	StockInstrument(const StockInstrument&) = delete;
	StockInstrument& operator=(const StockInstrument&) = delete;

	// Note VS2013 does not support implicit generation of move constructors
	StockInstrument(StockInstrument&& old)
		: id_(std::move(old.id_)), name_(std::move(old.name_)), isin_(std::move(old.isin_)), mnemo_(std::move(old.mnemo_))
	{
	}

	// Note VS2013 does not support implicit generation of move assignment operators
	StockInstrument& operator=(StockInstrument&& old)
	{
		id_ = std::move(old.id_);
		name_ = std::move(old.name_);
		isin_ = std::move(old.isin_);
		mnemo_ = std::move(old.mnemo_);
		return *this;
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
	// Note: do not forget to update move implementations.
	InstrumentIDType id_;
	std::string name_;
	std::string isin_;
	std::string mnemo_;
};

#endif