#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <memory>
#include <unordered_map>
#include "OrderBook.h"

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
class MatchingEngine
{
	// Instrument traits
	typedef typename InstrumentTraits::InstrumentIDType InstrumentID;

	// Order traits
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

	// Aliases
	typedef Order<OrderTraits, InstrumentTraits> OrderType;
	typedef OrderBook<OrderTraits, InstrumentTraits> OrderBookType;

public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>> instrument);

	bool AddOrder(OrderType& order);
	bool ModOrder(const OrderID& orderID, OrderType& newOrder);
	bool DelOrder(const OrderID& orderID);

private:
	// Key: mnemo
	// Value: order book
	std::unordered_map<InstrumentID, OrderBookType> orderBooks_;
};

#include "MatchingEngine.hxx"

#endif