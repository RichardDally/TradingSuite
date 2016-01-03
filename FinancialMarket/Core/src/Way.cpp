#include "Way.h"
#include <type_traits>

namespace
{
	static const char* const wayAsString[] =
	{
		"UNDEFINED",
		"BUY",
		"SELL"
	};
}

const char* const WayToString(const Way way)
{
    static_assert(std::is_same<std::underlying_type<Way>::type, int>::value, "Way underlying type is incorrect");
    static_assert(sizeof(wayAsString) / sizeof(wayAsString[0]) == static_cast<size_t>(Way::MAX), "Way enum and strings are not matching");
    return wayAsString[static_cast<std::underlying_type<Way>::type>(way)];
}