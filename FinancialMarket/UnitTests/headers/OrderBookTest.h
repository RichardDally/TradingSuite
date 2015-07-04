#pragma once
#ifndef ORDER_BOOK_TEST_H_
#define ORDER_BOOK_TEST_H_

#include <OrderBook.h>

template <typename OrderTraits, typename InstrumentTraits>
class OrderBookExposed : public OrderBook<OrderTraits, InstrumentTraits>
{
public:
    const OrderContainer& GetOrdersContainer() const
    {
        return orders_;
    }
};

#endif