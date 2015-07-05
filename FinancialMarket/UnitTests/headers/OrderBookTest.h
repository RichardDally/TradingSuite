#pragma once
#ifndef ORDER_BOOK_TEST_H_
#define ORDER_BOOK_TEST_H_

#include <OrderBook.h>

/**
* @brief Expose protected attributes/members of OrderBook class
*/
template <typename OrderTraits, typename InstrumentTraits>
class OrderBookExposed : public OrderBook<OrderTraits, InstrumentTraits>
{
public:
    const typename OrderBook<OrderTraits, InstrumentTraits>::OrderContainer& GetOrdersContainer() const
    {
        return this->orders_;
    }
};

#endif
