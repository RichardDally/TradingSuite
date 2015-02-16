#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <string>

template <typename InstrumentID, typename Derived>
class Instrument
{
public:
	// Unique identifier of instrument
	const InstrumentID& GetInstrumentID() const
	{
		return static_cast<Derived*>(this)->GetInstrumentID();
	}

	// Get human readable name
	const std::string& GetName() const
	{
		return static_cast<Derived*>(this)->GetName();
	}

	// Get International Securities Identification Number (ISIN)
	const std::string& GetISIN() const
	{
		return static_cast<Derived*>(this)->GetISIN();
	}

	// Get mnenonic name
	const std::string& GetMnemo() const
	{
		return static_cast<Derived*>(this)->GetMnemo();
	}
};

#endif