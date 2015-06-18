#pragma once
#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

#include <memory>
#include <unordered_map>
#include "GenericOrder.h"

template <typename OrderTraits, typename InstrumentTraits>
class OrderBook
{
	// Order traits
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

	// Aliases
	using Order = GenericOrder<OrderTraits, InstrumentTraits>;

public:
	OrderBook() = default;
	~OrderBook() = default;
	OrderBook(const OrderBook&) = delete;
	OrderBook& operator=(const OrderBook&) = delete;
	
	// Note VS2013 does not support implicit generation of move constructors
	OrderBook(OrderBook&& old)
		: bid(std::move(old.bid)), ask(std::move(old.ask))
	{
	}

	// Note VS2013 does not support implicit generation of move assignment operators
	OrderBook& operator=(OrderBook&& old)
	{
		bid = std::move(old.bid);
		ask = std::move(old.ask);
		return *this;
	}

	/**
	* @brief Add an order to order book
	* @note order id is filled
	*/
	bool AddOrder(std::shared_ptr<Order>&& order);

	/**
	* @brief Modify an order in order book
	* @note order id may change
	*/
	bool ModOrder(Order& newOrder);

	/**
	* @brief Delete an order from order book
	*/
	bool DelOrder(const Order& order);

	/**
	* @brief Display on std::cout order book content
	* @note Debug purpose
	*/
	void Dump() const;

	bool GetOrder(const OrderID& orderID, Order& result) const;

private:
    std::unordered_map<OrderID, std::shared_ptr<Order>> bid;
    std::unordered_map<OrderID, std::shared_ptr<Order>> ask;

	auto Find(const OrderID& orderID) -> decltype(bid.begin())
    {
		// TODO: test
		static_assert(decltype(bid.begin()) == decltype(ask.begin()), "bid and ask containers must have same type");
        auto it = bid.find(id);
        if (it == bid.end())
        {
            it = ask.find(id);
        }
        return it;
    }
};

#include "OrderBook.hxx"

#endif