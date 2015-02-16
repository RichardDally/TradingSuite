#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

#include <unordered_map>
#include "Order.h"

template <typename OrderID, typename Quantity, typename Price>
class OrderBook
{
	typedef Order<OrderID, Quantity, Price> OrderType;

public:
	OrderBook();
	bool AddOrder(Order<OrderID, Quantity, Price>& order);
	bool ModOrder(const OrderID& orderID, Order<OrderID, Quantity, Price>& newOrder);
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