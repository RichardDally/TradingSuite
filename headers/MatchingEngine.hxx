#ifndef MATCHING_ENGINE_HXX_
#define MATCHING_ENGINE_HXX_

#include "Instrument.h"
#include "MatchingEngine.h"

template <typename InstrumentType, typename InstrumentTraits, typename OrderTraits>
void MatchingEngine<InstrumentType, InstrumentTraits, OrderTraits>::AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>> instrument)
{
	orderBooks_.insert({ instrument->GetInstrumentID(), std::move(OrderBookType()) });
}

template <typename InstrumentType, typename InstrumentTraits, typename OrderTraits>
bool MatchingEngine<InstrumentType, InstrumentTraits, OrderTraits>::AddOrder(OrderType& order)
{
	return true;
}

template <typename InstrumentType, typename InstrumentTraits, typename OrderTraits>
bool MatchingEngine<InstrumentType, InstrumentTraits, OrderTraits>::ModOrder(const OrderID& orderID, OrderType& newOrder)
{
	return true;
}

template <typename InstrumentType, typename InstrumentTraits, typename OrderTraits>
bool MatchingEngine<InstrumentType, InstrumentTraits, OrderTraits>::DelOrder(const OrderID& orderID)
{
	return true;
}

#endif