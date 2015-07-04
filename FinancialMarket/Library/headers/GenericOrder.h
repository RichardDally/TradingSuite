#pragma once
#ifndef GENERIC_ORDER_H_
#define GENERIC_ORDER_H_

#include "Way.h"

template <typename OrderTraits, typename InstrumentTraits>
struct GenericOrder
{
	// Instrument traits
	typedef typename InstrumentTraits::InstrumentIDType InstrumentID;

	// Order traits
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

	// Ctor without order id
	explicit GenericOrder(const InstrumentID& instrumentID, const Way way, const Quantity& quantity, const Price& price)
		: instrumentID_(instrumentID), way_(way), quantity_(quantity), price_(price)
	{
	}

	// Ctor used by matching engine
	explicit GenericOrder(const OrderID& orderID, const InstrumentID& instrumentID, const Way way, const Quantity& quantity, const Price& price)
        : orderID_(orderID), instrumentID_(instrumentID), way_(way), quantity_(quantity), price_(price)
	{
	}

    // Ctor used to modify existing orders
    explicit GenericOrder(const OrderID& orderID, const Quantity& quantity, const Price& price)
        : orderID_(orderID), quantity_(quantity), price_(price)
    {
    }

	~GenericOrder() = default;
	GenericOrder(const GenericOrder&) = delete;
	GenericOrder& operator=(const GenericOrder&) = delete;

	// Note VS2013 does not support implicit generation of move constructors
	GenericOrder(GenericOrder&& old)
		:
		orderID_(std::move(old.orderID_)),
		instrumentID_(std::move(old.instrumentID_)),
		way_(std::move(old.way_)),
		quantity_(std::move(old.quantity_)),
		price_(std::move(old.price_))
	{
	}

	// Note VS2013 does not support implicit generation of move assignment operators
	GenericOrder& operator=(GenericOrder&& old)
	{
		orderID_ = std::move(old.orderID_);
		instrumentID_ = std::move(old.instrumentID_);
		way_ = std::move(old.way_);
		quantity_ = std::move(old.quantity_);
		price_ = std::move(old.price_);
		return *this;
	}

	// Note: do not forget to update move implementations.
    OrderID orderID_; // TODO: initialize orderID_ with template specialization
	InstrumentID instrumentID_;
	Way way_;
    Quantity quantity_;
    Price price_;
};

#endif