#pragma once
#ifndef ORDER_TRAITS_H_
#define ORDER_TRAITS_H_

template <typename OrderID, typename Quantity, typename Price>
struct OrderTraits
{
	static_assert(sizeof(OrderID) != sizeof(OrderID), "Must use specialized traits");
	static_assert(sizeof(Quantity) != sizeof(Quantity), "Must use specialized traits");
	static_assert(sizeof(Price) != sizeof(Price), "Must use specialized traits");
	typedef OrderID OrderIDType;
	typedef Quantity QuantityType;
	typedef Price PriceType;
};

template <>
struct OrderTraits<int, int, int>
{
	typedef int OrderIDType;
	typedef int QuantityType;
	typedef int PriceType;
};

#endif