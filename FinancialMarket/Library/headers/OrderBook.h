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

public:
    // Aliases
    using OrderType = GenericOrder<OrderTraits, InstrumentTraits>;
    using PointerType = std::shared_ptr<OrderType>;

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
    bool AddOrder(std::shared_ptr<OrderType>&& order);

	/**
	* @brief Modify an order in order book
	* @note order id may change
	*/
    bool ModOrder(OrderType& newOrder);

	/**
	* @brief Delete an order from order book
	*/
    bool DelOrder(const OrderType& order);

	/**
	* @brief Display on std::cout order book content
	* @note Debug purpose
	*/
	void Dump() const;

    /**
    * @brief Retrieve an order
    * @note Existing shared_ptr is duplicated
    */
    PointerType GetOrder(const OrderID& orderID) const;

private:
    std::unordered_map<OrderID, std::shared_ptr<OrderType>> bid;
    std::unordered_map<OrderID, std::shared_ptr<OrderType>> ask;
};

#include "OrderBook.hxx"

#endif