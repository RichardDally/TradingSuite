#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include <string>
#include <iostream>

// Instrument interface
class Instrument
{
public:
	//Instrument() = default;
	virtual ~Instrument() { std::cout << "Instrument dtor" << std::endl; }
	//Instrument(const Instrument&) = default;
	//Instrument& operator=(const Instrument&) = default;

	// Get human readable name
	virtual const std::string& GetName() const = 0;

	// Get International Securities Identification Number (ISIN)
	virtual const std::string& GetISIN() const = 0;

	// Get mnenonic name
	virtual const std::string& GetMnemo() const = 0;
};

#endif