#pragma once
#ifndef ORDER_FACTORY_H_
#define ORDER_FACTORY_H_

#include <memory>

class OrderFactory
{
public:
    template <typename OrderType, typename... Args>
    static std::shared_ptr<OrderType> BuildOrder(Args&&... args)
    {
        return std::make_shared<OrderType>(std::forward<Args>(args)...);
    }
};

#endif