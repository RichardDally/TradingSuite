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
    typedef int OrderID;
	typedef Order<OrderID, Quantity, Price> OrderType;

public:
    OrderBook() {}

    // Returns OrderID
    OrderID AddOrder(const Way way, const Quantity& quantity, const Price& price)
    {
        // TODO: improve order id generation
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

    bool GetOrder(const OrderID& orderID, OrderType& result)
    {
        auto it = Find(orderID);
        if (it != bid.end() && it != ask.end())
        {
            result = it->second;
            return true;
        }
        return false;
    }

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