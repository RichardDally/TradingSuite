#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <memory>
#include <unordered_map>
#include "OrderBook.h"

template <typename InstrumentID, typename InstrumentType, typename OrderID, typename Quantity, typename Price>
class MatchingEngine
{
	typedef Order<OrderID, Quantity, Price> OrderType;
	typedef OrderBook<OrderID, Quantity, Price> OrderBookType;

public:
	void AddInstrument(std::shared_ptr<Instrument<InstrumentID, InstrumentType>> instrument);

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