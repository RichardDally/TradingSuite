#ifndef MATCHING_ENGINE_HXX_
#define MATCHING_ENGINE_HXX_

#include "MatchingEngine.h"

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
void MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::CreateOrderBook(const InstrumentID& id)
{
	if (orderBooks_.find(id) == orderBooks_.end())
	{
		orderBooks_.emplace(id, std::move(OrderBookType()));
	}
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::AddOrder(std::shared_ptr<Order>&& order)
{
	bool result = false;

	// Find order book related to instrument id
	auto it = orderBooks_.find(order->instrumentID_);
	if (it != orderBooks_.end())
	{
		result = it->second.AddOrder(std::move(order));
	}
	else
	{
		// TODO: log an error about "instrument id has been not found"
	}

	return result;
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::ModOrder(Order& newOrder)
{
	bool result = false;

	// Find order book related to instrument id
	auto it = orderBooks_.find(order.instrumentID_);
    if (it != orderBooks_.end())
	{
		result = it->second->ModOrder(newOrder);
	}
	else
	{
		// TODO: log an error about "instrument id has been not found"
	}

	return result;
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::DelOrder(const Order& order)
{
	bool result = false;

	// Find order book related to instrument id
	auto it = orderBooks_.find(order.instrumentID_);
    if (it != orderBooks_.end())
	{
        result = it->second->DelOrder(order.orderID_);
	}
	else
	{
		// TODO: log an error about "instrument id has been not found"
	}

	return result;
}

#endif