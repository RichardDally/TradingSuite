#ifndef MATCHING_ENGINE_HXX_
#define MATCHING_ENGINE_HXX_

#include "Instrument.h"
#include "MatchingEngine.h"

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
void MatchingEngine<InstrumentType, InstrumentTraits, OrderID, Quantity, Price>::AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>> instrument)
{
	orderBooks_.insert({ instrument->GetInstrumentID(), std::move(OrderBookType()) });
}

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
bool MatchingEngine<InstrumentType, InstrumentTraits, OrderID, Quantity, Price>::AddOrder(OrderType& order)
{
	return true;
}

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
bool MatchingEngine<InstrumentType, InstrumentTraits, OrderID, Quantity, Price>::ModOrder(const OrderID& orderID, OrderType& newOrder)
{
	return true;
}

template <typename InstrumentType, typename InstrumentTraits, typename OrderID, typename Quantity, typename Price>
bool MatchingEngine<InstrumentType, InstrumentTraits, OrderID, Quantity, Price>::DelOrder(const OrderID& orderID)
{
	return true;
}

#endif