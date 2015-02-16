#ifndef ORDER_H_
#define ORDER_H_

#include "OrderID.hxx"

enum class Way : int
{
	BUY,
	SELL
};

template <typename OrderID, typename Quantity, typename Price>
struct Order
{
public:
	explicit Order(const Way way, const Quantity& quantity, const Price& price)
		: way_(way), quantity_(quantity), price_(price)
	{
	}

	explicit Order(const OrderID& orderID, const Way way, const Quantity& quantity, const Price& price)
		: orderID_(orderID), way_(way), quantity_(quantity), price_(price)
	{
	}

	const Way way_;
    OrderID orderID_; // TODO: initialize orderID_ with template specialization
    Quantity quantity_;
    Price price_;
};

#endif