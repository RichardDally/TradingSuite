#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

#include <unordered_map>
#include "Order.h"

template <typename OrderTraits>
class OrderBook
{
	typedef typename OrderTraits::OrderIDType OrderID;
	typedef typename OrderTraits::QuantityType Quantity;
	typedef typename OrderTraits::PriceType Price;

	typedef Order<OrderTraits> OrderType;

public:
	OrderBook();
	bool AddOrder(OrderType& order);
	bool ModOrder(const OrderID& orderID, OrderType& newOrder);
	bool DelOrder(const OrderID& orderID);

    // Debug purpose
	void Dump();

	bool GetOrder(const OrderID& orderID, OrderType& result) const;

private:
	std::unordered_map<OrderID, OrderType> bid;
	std::unordered_map<OrderID, OrderType> ask;

	auto Find(const OrderID& orderID) -> decltype(bid.begin())
    {
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