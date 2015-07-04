#include <gtest/gtest.h>

#include "OrderBook.h"
#include "OrderTraits.h"
#include "OrderFactory.h"
#include "InstrumentTraits.h"

TEST(OrderBookTest, AddOrder)
{
    using SimpleOrderIDType = int;
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using SimpleOrderTraits = OrderTraits<SimpleOrderIDType, int, int>;
    using SimpleOrderType = GenericOrder<SimpleOrderTraits, SimpleInstrumentTraits>;
    OrderBook<SimpleOrderTraits, SimpleInstrumentTraits> orderBook;

    const SimpleOrderIDType orderID = 0;
    auto genuineOrder = OrderFactory::BuildOrder<SimpleOrderType>(orderID, Way::BUY, 10, 15);
    orderBook.AddOrder(std::move(genuineOrder));
    // genuineOrder is now empty
    auto retrievedOrder = orderBook.GetOrder(orderID);
    EXPECT_TRUE(retrievedOrder.operator bool());
    EXPECT_EQ(2, retrievedOrder.use_count());
}
