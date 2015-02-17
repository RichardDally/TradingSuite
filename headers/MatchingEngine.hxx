#ifndef MATCHING_ENGINE_HXX_
#define MATCHING_ENGINE_HXX_

#include "Instrument.h"
#include "MatchingEngine.h"

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
void MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::AddInstrument(std::shared_ptr<Instrument<InstrumentType, InstrumentTraits>> instrument)
{
	orderBooks_.insert({ instrument->GetInstrumentID(), std::move(OrderBookType()) });
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::AddOrder(OrderType& order)
{
	return true;
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::ModOrder(const OrderID& orderID, OrderType& newOrder)
{
	return true;
}

template <typename InstrumentType, typename OrderTraits, typename InstrumentTraits>
bool MatchingEngine<InstrumentType, OrderTraits, InstrumentTraits>::DelOrder(const OrderID& orderID)
{
	return true;
}

#endif