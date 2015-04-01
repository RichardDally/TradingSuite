#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <unordered_map>
#include "OrderBook.h"

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
class MatchingEngine
{
	// Order traits
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

	// Aliases
	typedef Order<OrderTraits, InstrumentTraits> OrderType;
	typedef OrderBook<OrderTraits, InstrumentTraits> OrderBookType;

public:
	// Instrument traits
	typedef typename InstrumentTraits::InstrumentIDType InstrumentID;

	/**
	* @brief Create a raw order book
	*/
	void CreateOrderBook(const InstrumentID& id);

	/**
	* @brief Find order book matching instrument id then add order to it
	*/
	bool AddOrder(OrderType& order);

	/**
	* @brief Find order book matching instrument id then modify order within
	*/
	bool ModOrder(OrderType& newOrder);

	/**
	* @brief Find order book matching instrument id then delete order from it
	*/
	bool DelOrder(const OrderType& orderID);

private:
	// Key: instrument id
	// Value: order book
	std::unordered_map<InstrumentID, OrderBookType> orderBooks_;
};

#include "MatchingEngine.hxx"

#endif