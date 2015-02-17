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

	explicit Order(const Way way, const Quantity& quantity, const Price& price)
		: way_(way), quantity_(quantity), price_(price)
	{
	}

	explicit Order(const OrderID& orderID, const Way way, const Quantity& quantity, const Price& price)
		: orderID_(orderID), way_(way), quantity_(quantity), price_(price)
	{
	}

	const Way way_;
	InstrumentID instrumentID_;
    OrderID orderID_; // TODO: initialize orderID_ with template specialization
    Quantity quantity_;
    Price price_;
};

#endif