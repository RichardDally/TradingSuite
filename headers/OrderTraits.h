#ifndef ORDER_TRAITS_H_
#define ORDER_TRAITS_H_

template <typename OrderID, typename Quantity, typename Price>
struct OrderTraits
{
	typedef OrderID OrderIDType;
	typedef Quantity QuantityType;
	typedef Price PriceType;
};

#endif