#ifndef INSTRUMENT_TRAITS_H_
#define INSTRUMENT_TRAITS_H_

template <typename InstrumentID>
struct InstrumentTraits
{
	static_assert(sizeof(InstrumentID) != sizeof(InstrumentID), "Must use specialized traits");
	typedef InstrumentID InstrumentIDType;
};

template <>
struct InstrumentTraits<int>
{
	typedef int InstrumentIDType;
};

#endif