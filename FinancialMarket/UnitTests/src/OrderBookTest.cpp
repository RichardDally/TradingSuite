#include <gtest/gtest.h>

#include <iostream>
#include "OrderBookTest.h"
#include <EpochTimestamp.hxx>
#include <OrderTraits.h>
#include <OrderFactory.h>
#include <InstrumentTraits.h>

using SimpleInstrumentIDType = int;
using SimpleOrderIDType = int;
using SimpleQuantityType = int;
using SimplePriceType = int;
using SimpleInstrumentTraits = InstrumentTraits<int>;
using SimpleOrderTraits = OrderTraits<SimpleOrderIDType, SimpleQuantityType, SimplePriceType>;
using SimpleOrderType = GenericOrder<SimpleOrderTraits, SimpleInstrumentTraits>;

const SimpleInstrumentIDType instrumentID = 42;

TEST(OrderBookTest, AddOrder)
{
    OrderBookExposed<SimpleOrderTraits, SimpleInstrumentTraits> orderBook;
    auto genuineOrder = OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::BUY, 10, 15, EpochTimestamp());

    const auto addingResult = orderBook.AddOrder(genuineOrder);
    EXPECT_TRUE(addingResult);
    EXPECT_EQ(1, orderBook.GetOrdersContainer().size());
    EXPECT_EQ(2, genuineOrder.use_count());
}

TEST(OrderBookTest, ModifyOrder)
{
    OrderBookExposed<SimpleOrderTraits, SimpleInstrumentTraits> orderBook;
    auto genuineOrder = OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::BUY, 10, 15, EpochTimestamp());
    const auto addingResult = orderBook.AddOrder(genuineOrder);
    EXPECT_TRUE(addingResult);

    // Modify existing order (increasing quantity)
    auto modifiedOrder = orderBook.ModOrder(OrderFactory::BuildLightOrder<SimpleOrderType>(genuineOrder->orderID_, 30, 15));
    EXPECT_TRUE(modifiedOrder.operator bool());
    EXPECT_EQ(3, modifiedOrder.use_count());
}

TEST(OrderBookTest, DeleteOrder)
{
    OrderBookExposed<SimpleOrderTraits, SimpleInstrumentTraits> orderBook;
    auto genuineOrder = OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::BUY, 10, 15, EpochTimestamp());
    const auto addingResult = orderBook.AddOrder(genuineOrder);
    EXPECT_TRUE(addingResult);

    // Delete existing order
    auto result = orderBook.DelOrder(genuineOrder);
    EXPECT_TRUE(result);
    result = orderBook.DelOrder(genuineOrder);
    EXPECT_FALSE(result);
}

TEST(OrderBookTest, MultiIndex)
{
    OrderBookExposed<SimpleOrderTraits, SimpleInstrumentTraits>::MultiIndexOrderContainer c;
    c.insert(OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::BUY, 10, 15, EpochTimestamp()));
    c.insert(OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::BUY, 10, 14, EpochTimestamp()));
    c.insert(OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::BUY, 10, 13, EpochTimestamp()));

    c.insert(OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::SELL, 10, 16, EpochTimestamp()));
    c.insert(OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::SELL, 10, 17, EpochTimestamp()));
    c.insert(OrderFactory::BuildOrder<SimpleOrderType>(instrumentID, Way::SELL, 10, 18, EpochTimestamp()));

    auto it = c.get<way>().find(Way::BUY);
    const auto end = c.get<way>().end();

    std::cout << "-----" << std::endl;
    for (; it != end; ++it)
    {
        (*it)->Dump();
        std::cout << "-----" << std::endl;
    }

    //auto it = c.get<OrderBookExposed<SimpleOrderTraits, SimpleInstrumentTraits>::OrderType::way_>().find(Way::BUY);
}