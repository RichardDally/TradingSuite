#ifndef MATCHING_ENGINE_HXX_
#define MATCHING_ENGINE_HXX_

#include "Instrument.h"
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
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::AddOrder(OrderType& order)
{
	bool result = false;

	// Find order book related to instrument id
	auto it = orderBooks_.find(order.instrumentID_);
	if (it != orderBooks.end())
	{
		result = it->second->AddOrder(order);
	}
	else
	{
		// TODO: log an error about "instrument id has been not found"
	}

	return result;
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::ModOrder(OrderType& newOrder)
{
	bool result = false;

	// Find order book related to instrument id
	auto it = orderBooks_.find(order.instrumentID_);
	if (it != orderBooks.end())
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
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::DelOrder(const OrderType& orderID)
{
	bool result = false;

	// Find order book related to instrument id
	auto it = orderBooks_.find(order.instrumentID_);
	if (it != orderBooks.end())
	{
		result = it->second->DelOrder(orderID);
	}
	else
	{
		// TODO: log an error about "instrument id has been not found"
	}

	return result;
}

#endif