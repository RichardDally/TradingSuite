#pragma once
#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <string>

template <typename Derived, typename Traits>
class Instrument
{
	// Instrument traits
	typedef typename Traits::InstrumentIDType InstrumentIDType;

public:
	// Unique identifier of instrument
	const InstrumentIDType& GetInstrumentID() const
	{
		return static_cast<const Derived*>(this)->GetInstrumentID();
	}

	// Get human readable name
	const std::string& GetName() const
	{
		return static_cast<const Derived*>(this)->GetName();
	}

	// Get International Securities Identification Number (ISIN)
	const std::string& GetISIN() const
	{
		return static_cast<const Derived*>(this)->GetISIN();
	}

	// Get mnenonic name
	const std::string& GetMnemo() const
	{
		return static_cast<const Derived*>(this)->GetMnemo();
	}
};

#endif