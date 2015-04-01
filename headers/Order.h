#ifndef ORDER_H_
#define ORDER_H_

#include "Way.h"

template <typename OrderTraits, typename InstrumentTraits>
struct Order
{
	// Instrument traits
	typedef typename InstrumentTraits::InstrumentIDType InstrumentID;

	// Order traits
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

	// Ctor without order id (order is not registered in matching engine yet)
	explicit Order(const InstrumentID& instrumentID, const Way way, const Quantity& quantity, const Price& price)
		: instrumentID_(instrumentID), way_(way), quantity_(quantity), price_(price)
	{
	}

	// Ctor used by matching engine
	explicit Order(const OrderID& orderID, const InstrumentID& instrumentID, const Way way, const Quantity& quantity, const Price& price)
		: orderID_(orderID), Order(instrumentID, way, quantity, price)
	{
	}

	~Order() = default;

    OrderID orderID_; // TODO: initialize orderID_ with template specialization
	InstrumentID instrumentID_;
	Way way_;
    Quantity quantity_;
    Price price_;
};

#endif