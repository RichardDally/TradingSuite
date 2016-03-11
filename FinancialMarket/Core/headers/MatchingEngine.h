#pragma once
#ifndef MATCHING_ENGINE_H_
#define MATCHING_ENGINE_H_

#include <unordered_map>
#include "OrderBook.h"

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
class MatchingEngine
{
	// Order traits
	using OrderIDType = typename OrderTraits::OrderIDType;
	using QuantityType = typename OrderTraits::QuantityType;
	using PriceType = typename OrderTraits::PriceType;

	// Aliases
	using Order = GenericOrder<OrderTraits, InstrumentTraits>;
	using OrderBookType = OrderBook<OrderTraits, InstrumentTraits>;

public:
	// Instrument traits
	using InstrumentIDType = typename InstrumentTraits::InstrumentIDType;

	/**
	* @brief Create a raw order book
	* @note Existing order books are not overwritten
	*/
    void CreateOrderBook(const InstrumentIDType& id);

	/**
	* @brief Find order book matching instrument id then add order to it
	*/
    bool AddOrder(std::shared_ptr<Order>&& order);

	/**
	* @brief Find order book matching instrument id then modify order within
	*/
	bool ModOrder(Order& newOrder);

	/**
	* @brief Find order book matching instrument id then delete order from it
	*/
	bool DelOrder(const Order& order);

private:
	// Key: instrument id
	// Value: order book
    std::unordered_map<InstrumentIDType, OrderBookType> orderBooks_;
};

#include "MatchingEngine.hxx"

#endif