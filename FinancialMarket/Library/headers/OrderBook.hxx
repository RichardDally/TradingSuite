#pragma once
#ifndef ORDER_BOOK_HXX_
#define ORDER_BOOK_HXX_

#include <iostream>
#include "OrderBook.h"

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::AddOrder(PointerType order)
{
	bool result = false;

	// TODO: improve order id generation
    static OrderID orderCounter = 0;

    // Set order id for this new order
    order->orderID_ = orderCounter;

    //assert(orders_.find(orderCounter) == orders_.end());
    orders_[orderCounter] = std::move(order);

	return true;
}

template <typename OrderTraits, typename InstrumentTraits>
typename OrderBook<OrderTraits, InstrumentTraits>::PointerType OrderBook<OrderTraits, InstrumentTraits>::ModOrder(LightPointerType&& newOrder)
{
    // Retrieve existing order
    auto order = GetOrder(newOrder->orderID_);

	// Modify order
	if (order)
	{
		order->price_ = newOrder->price_;
		order->quantity_ = newOrder->quantity_;
	}
	else
	{
		// TODO: log order not found
	}

	return order;
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::DelOrder(const PointerType& order)
{
	bool result = false;

    auto it = orders_.find(order->orderID_);
    if (it != orders_.end())
	{
        orders_.erase(it);
		result = true;
	}

	return result;
}

template <typename OrderTraits, typename InstrumentTraits>
void OrderBook<OrderTraits, InstrumentTraits>::Dump() const
{
    assert(!"Not implemented");
}

template <typename OrderTraits, typename InstrumentTraits>
typename OrderBook<OrderTraits, InstrumentTraits>::PointerType OrderBook<OrderTraits, InstrumentTraits>::GetOrder(const OrderID& orderID) const
{
    OrderBook<OrderTraits, InstrumentTraits>::PointerType order;

    auto it = orders_.find(orderID);
    if (it != orders_.end())
    {
        order = it->second;
    }
    
    return order;
}

#endif
