#ifndef ORDER_H_
#define ORDER_H_

template <typename OrderID, typename Quantity, typename Price>
struct Order
{
public:
	explicit Order(const OrderID& orderID, const Quantity& quantity, const Price& price)
        : orderID_(orderID), quantity_(quantity), price_(price)
	{
	}

    OrderID orderID_;
    Quantity quantity_;
    Price price_;
};

#endif