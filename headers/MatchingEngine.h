#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <memory>
#include <unordered_map>
#include "OrderBook.h"

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
class MatchingEngine
{
	typedef Order<OrderID, Quantity, Price> OrderType;
	typedef OrderBook<OrderID, Quantity, Price> OrderBookType;

public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>> instrument);

	bool AddOrder(OrderType& order);
	bool ModOrder(const OrderID& orderID, OrderType& newOrder);
	bool DelOrder(const OrderID& orderID);

private:
	// Key: mnemo
	// Value: order book
	std::unordered_map<typename InstrumentTraits::InstrumentIDType, OrderBookType> orderBooks_;
};

#include "MatchingEngine.hxx"

#endif