#pragma once
#ifndef ORDER_FACTORY_H_
#define ORDER_FACTORY_H_

#include <memory>

struct OrderFactory
{
    /**
    * @brief Create any order you want
    * @note All orders must be created that way.
    */
    template <typename OrderType, typename... Args>
    static std::shared_ptr<OrderType> BuildOrder(Args&&... args)
    {
        return std::make_shared<OrderType>(std::forward<Args>(args)...);
    }

    template <typename OrderType, typename... Args>
    static std::unique_ptr<OrderType> BuildLightOrder(Args&&... args)
    {
        return std::unique_ptr<OrderType>(new OrderType(std::forward<Args>(args)...));
    }
};

#endif