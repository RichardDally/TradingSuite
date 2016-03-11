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

const char* const WayToString(const Way way);

#endif