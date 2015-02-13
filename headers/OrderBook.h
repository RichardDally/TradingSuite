#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

#include <unordered_map>
#include "Order.h"

enum class Way
{
    BUY,
    SELL
};

template <typename Quantity, typename Price>
class OrderBook
{
public:
	typedef int OrderID;
	typedef Order<OrderID, Quantity, Price> OrderType;

	OrderBook();

    // Returns OrderID
	OrderID AddOrder(const Way way, const Quantity& quantity, const Price& price);

	// Modifies an order by order id
	void ModOrder(const OrderID& id, const Quantity& quantity, const Price& price);

	// Delete order by order id
	void DelOrder(const OrderID& id, const Quantity& quantity, const Price& price);

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