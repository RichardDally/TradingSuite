#pragma once
#ifndef WAY_H_
#define WAY_H_

enum class Way : int
{
    UNDEFINED,
    BUY,
    SELL,
    MAX
};

static const char* const wayAsString[] =
{
    "UNDEFINED",
    "BUY",
    "SELL"
};
static_assert(sizeof(wayAsString) / sizeof(wayAsString[0]) == static_cast<size_t>(Way::MAX), "Way enum and strings are not matching");

const char* const WayToString(const Way way)
{
    return wayAsString[static_cast<int>(way)];
}

#endif