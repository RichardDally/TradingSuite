#ifndef ORDER_BOOK_HXX_
#define ORDER_BOOK_HXX_

#include "OrderBook.h"

template <typename Quantity, typename Price>
OrderBook<Quantity, Price>::OrderBook()
{
}

template <typename Quantity, typename Price>
typename OrderBook<Quantity, Price>::OrderID
OrderBook<Quantity, Price>::AddOrder(const Way way, const Quantity& quantity, const Price& price)
{
	// TODO: improve order id generation
	if (way == Way::BUY)
	{
		static OrderID counter = 0;
		bid.emplace(counter++, OrderType(counter, quantity, price));
		return counter;
	}
	else if (way == Way::SELL)
	{
		static OrderID counter = 0;
		ask.emplace(counter++, OrderType(counter, quantity, price));
		return counter;
	}
	// TODO: throw exception
}

template <typename Quantity, typename Price>
void OrderBook<Quantity, Price>::ModOrder(const OrderID& id, const Quantity& quantity, const Price& price)
{
	auto it = bid.find(id);
	if (it == bid.end())
	{
		it = ask.find(id);
		if (it == ask.end())
		{
			// Order $id not found
			return;
		}
	}
	// Modify order
	it->second.price_ = price;
	it->second.quantity_ = quantity;
}

template <typename Quantity, typename Price>
void OrderBook<Quantity, Price>::DelOrder(const OrderID& id, const Quantity& quantity, const Price& price)
{
	auto it = bid.find(id);
	if (it != bid.end())
	{
		bid.erase(id);
		return;
	}

	it = ask.find(id);
	if (it != ask.end())
	{
		ask.erase(it);
		return;
	}
}

template <typename Quantity, typename Price>
void OrderBook<Quantity, Price>::Dump()
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

template <typename Quantity, typename Price>
bool OrderBook<Quantity, Price>::GetOrder(const OrderID& orderID, OrderType& result) const
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