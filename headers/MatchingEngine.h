#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <memory>
#include <unordered_map>
#include "OrderBook.h"

class Instrument;
class MatchingEngine
{
public:
	void AddInstrument(std::shared_ptr<Instrument> instrument);

private:
	// <quantity type, price type>
	// TODO: switch to double and handle them
	typedef OrderBook<int, int> OrderBookType;

	// Key: mnemo
	// Value: order book
	std::unordered_map<std::string, OrderBookType> orderBooks_;
};

#endif