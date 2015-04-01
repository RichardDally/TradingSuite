#ifndef ORDER_BOOK_HXX_
#define ORDER_BOOK_HXX_

#include "OrderBook.h"

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::AddOrder(Order& order)
{
	bool result = false;

	// TODO: improve order id generation
	if (order.way_ == Way::BUY)
	{
		static OrderID bidCounter = 0;
		order.orderID_ = bidCounter;
		result = bid.emplace(bidCounter++, OrderType(order)).second;
	}
	else if (order.way_ == Way::SELL)
	{
		static OrderID askCounter = 0;
		order.orderID_ = askCounter;
		result = ask.emplace(askCounter++, OrderType(order)).second;
	}

	return result;
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::ModOrder(Order& newOrder)
{
	bool result = false;
	OrderType* order = nullptr;

	// Find order
	if (order.way_ == Way::BUY)
	{
		auto it = bid.find(newOrder.orderID_);
		if (it != bid.end())
		{
			order = &it->second;
		}
	}
	else if (order.way_ == Way::SELL)
	{
		auto it = ask.find(newOrder.orderID_);
		if (it != ask.end())
		{
			order = &it->second;
		}
	}

	// Modify order
	if (order)
	{
		order->way_ = newOrder.way_;
		order->price_ = newOrder.price_;
		order->quantity_ = newOrder.quantity_;
		result = true;
	}
	else
	{
		// TODO: log order not found
	}

	return result;
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::DelOrder(const Order& order)
{
	bool result = false;

	// Find order
	if (order.way_ == Way::BUY)
	{
		auto it = bid.find(order.orderID_);
		if (it != bid.end())
		{
			bid.erase(it);
			result = true;
		}
	}
	else if (order.way_ == Way::SELL)
	{
		auto it = ask.find(orderID);
		if (it != ask.end())
		{
			ask.erase(it);
			result = true;
		}
	}

	return result;
}

template <typename OrderTraits, typename InstrumentTraits>
void OrderBook<OrderTraits, InstrumentTraits>::Dump() const
{
	std::cout << "--- Bid ---" << std::endl;
	for (const auto& pair : bid)
	{
		std::cout << "[" << pair.first << "] " << pair.second.quantity_ << "@" << pair.second.price_ << std::endl;
	}
	std::cout << "--- Ask ---" << std::endl;
	for (const auto& pair : bid)
	{
		std::cout << "[" << pair.first << "] " << pair.second.quantity_ << "@" << pair.second.price_ << std::endl;
	}
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::GetOrder(const OrderID& orderID, Order& result) const
{
	auto it = Find(orderID);
	if (it != bid.end() && it != ask.end())
	{
		result = it->second;
		return true;
	}
	return false;
}

#endif