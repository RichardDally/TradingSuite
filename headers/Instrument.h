#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <string>

// Instrument interface
class Instrument
{
public:
	virtual ~Instrument() {}

	virtual const std::string& GetUniqueIdentifier() const = 0;

	// Get human readable name
	virtual const std::string& GetName() const = 0;

	// Get International Securities Identification Number (ISIN)
	virtual const std::string& GetISIN() const = 0;

	// Get mnenonic name
	virtual const std::string& GetMnemo() const = 0;
};

#endif