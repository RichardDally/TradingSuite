#include "Instrument.h"
#include "MatchingEngine.h"

void MatchingEngine::AddInstrument(std::shared_ptr<Instrument> instrument)
{
	orderBooks_.insert({ instrument->GetUniqueIdentifier(), std::move(OrderBookType()) });
}