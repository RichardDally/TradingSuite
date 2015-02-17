#ifndef ORDER_BOOK_HXX_
#define ORDER_BOOK_HXX_

#include "OrderBook.h"

template <typename OrderTraits, typename InstrumentTraits>
OrderBook<OrderTraits, InstrumentTraits>::OrderBook()
{
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::AddOrder(OrderType& order)
{
	// TODO: improve order id generation
	if (order.way_ == Way::BUY)
	{
		static OrderID counter = 0;
		bid.emplace(counter++, OrderType(order));
		order.orderID_ = counter;
	}
	else if (order.way_ == Way::SELL)
	{
		static OrderID counter = 0;
		ask.emplace(counter++, OrderType(order));
		order.orderID_ = counter;
	}
	else
	{
		return false;
	}
	return true;
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::ModOrder(const OrderID& orderID, OrderType& newOrder)
{
	auto it = bid.find(orderID);
	if (it == bid.end())
	{
		it = ask.find(orderID);
		if (it == ask.end())
		{
			// OrderID has not been found
			return false;
		}
	}
	// Modify order
	it->second.price_ = price;
	it->second.quantity_ = quantity;
	return true;
}

template <typename OrderTraits, typename InstrumentTraits>
bool OrderBook<OrderTraits, InstrumentTraits>::DelOrder(const OrderID& orderID)
{
	auto it = bid.find(orderID);
	if (it != bid.end())
	{
		bid.erase(orderID);
		return true;
	}

	it = ask.find(orderID);
	if (it != ask.end())
	{
		ask.erase(orderID);
		return true;
	}

	return false;
}

template <typename OrderTraits, typename InstrumentTraits>
void OrderBook<OrderTraits, InstrumentTraits>::Dump()
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
bool OrderBook<OrderTraits, InstrumentTraits>::GetOrder(const OrderID& orderID, OrderType& result) const
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