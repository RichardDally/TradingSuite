#pragma once
#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

using namespace ::boost;
using namespace ::boost::multi_index;

#include <memory>
#include <unordered_map>
#include "GenericOrder.h"

template <typename OrderTraits, typename InstrumentTraits>
class OrderBook
{
protected:
	// Order traits
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

public:
    // Aliases
    using OrderType = GenericOrder<OrderTraits, InstrumentTraits>;
    using PointerType = std::shared_ptr<OrderType>;
    using LightPointerType = std::unique_ptr<OrderType>;
    using OrderContainer = std::unordered_map<OrderID, PointerType>;

    using MultiIndexOrderContainer = multi_index_container<PointerType,
        indexed_by<
            ordered_non_unique<
                composite_key<
                    OrderType,
                    member<OrderType, decltype(OrderType::way_), &OrderType::way_>,
                    member<OrderType, decltype(OrderType::price_), &OrderType::price_>,
                    member<OrderType, decltype(OrderType::timestamp_), &OrderType::timestamp_>
                >
            >,
            hashed_unique<
                member<OrderType, decltype(OrderType::orderID_), &OrderType::orderID_>
            >
        >
    >;

	OrderBook() = default;
	~OrderBook() = default;
	OrderBook(const OrderBook&) = delete;
	OrderBook& operator=(const OrderBook&) = delete;
	
	// Note VS2013 does not support implicit generation of move constructors
	OrderBook(OrderBook&& old)
		: orders_(std::move(old.orders_))
	{
	}

	// Note VS2013 does not support implicit generation of move assignment operators
	OrderBook& operator=(OrderBook&& old)
	{
        this->orders_ = std::move(old.orders_);
		return *this;
	}

	/**
	* @brief Add an order to order book
	* @note order id is filled
	*/
    bool AddOrder(PointerType order);

	/**
	* @brief Modify an order in order book
	* @note order id may change
	*/
    PointerType ModOrder(LightPointerType&& newOrder);

	/**
	* @brief Delete an order from order book
	*/
    bool DelOrder(const PointerType& order);

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

protected:
    OrderContainer orders_;
};

#include "OrderBook.hxx"

#endif