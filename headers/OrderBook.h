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
    typedef size_t OrderID;
	typedef Order<OrderID, Quantity, Price> OrderType;

public:
    OrderBook() {}

    // Returns OrderID
    OrderID AddOrder(const Way way, const Quantity& quantity, const Price& price)
    {
        // naive impl
        if (way == Way::BUY)
        {
            static OrderID counter = 0;
            bid.emplace(counter++, OrderType(counter, quantity, price));
            return counter;
        }
        else if (way == Way::SELL)
        {
            static OrderID counter = 0;
            ask.emplace(counter++, OrderType(counter, quantity, price));
            return counter;
        }
        // TODO: throw exception
    }

    void ModOrder(const OrderID& id, const Quantity& quantity, const Price& price)
    {
        auto it = bid.find(id);
        if (it == bid.end())
        {
            it = ask.find(id);
            if (it == ask.end())
            {
                // Order $id not found
                return;
            }
        }
        // Modify order
        it->second.price_ = price;
        it->second.quantity_ = quantity;
    }

    void DelOrder(const OrderID& id, const Quantity& quantity, const Price& price)
    {
        auto it = bid.find(id);
        if (it != bid.end())
        {
            bid.erase(id);
            return;
        }

        it = ask.find(id);
        if (it != ask.end())
        {
            ask.erase(it);
            return;
        }
    }

    // Debug purpose
    void Dump()
    {
        std::cout << "--- Bid ---" << std::endl;
        for (const auto& pair : bid)
        {
            std::cout << "[" << pair.first << "] " << pair.second.quantity_ << "@" << pair.second.price_ << std::endl;
        }
        std::cout << "--- Ask ---" << std::endl;
        for (const auto& pair : bid)
        {
            std::cout << "[" << pair.first << "] " << pair.second.quantity_ << "@" << pair.second.price_ << std::endl;
        }
    }

    const OrderType& GetOrder(const OrderID& orderID)
    {
    }

private:
    std::unordered_map<OrderID, OrderType> bid;
	std::unordered_map<OrderID, OrderType> ask;
};

#include "OrderBook.hxx"

#endif