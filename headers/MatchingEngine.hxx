#ifndef MATCHING_ENGINE_HXX_
#define MATCHING_ENGINE_HXX_

#include "Instrument.h"
#include "MatchingEngine.h"

template <typename InstrumentID, typename InstrumentType, typename OrderID, typename Quantity, typename Price>
void MatchingEngine<InstrumentID, InstrumentType, OrderID, Quantity, Price>::AddInstrument(std::shared_ptr<Instrument<InstrumentID, InstrumentType>> instrument)
{
	orderBooks_.insert({ instrument->GetUniqueIdentifier(), std::move(OrderBookType()) });
}

template <typename InstrumentID, typename InstrumentType, typename OrderID, typename Quantity, typename Price>
bool MatchingEngine<InstrumentID, InstrumentType, OrderID, Quantity, Price>::AddOrder(OrderType& order)
{
	return true;
}

template <typename InstrumentID, typename InstrumentType, typename OrderID, typename Quantity, typename Price>
bool MatchingEngine<InstrumentID, InstrumentType, OrderID, Quantity, Price>::ModOrder(const OrderID& orderID, OrderType& newOrder)
{
	return true;
}

template <typename InstrumentID, typename InstrumentType, typename OrderID, typename Quantity, typename Price>
bool MatchingEngine<InstrumentID, InstrumentType, OrderID, Quantity, Price>::DelOrder(const OrderID& orderID)
{
	return true;
}

#endif