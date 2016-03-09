#pragma once
#ifndef EPOCH_TIMESTAMP_HXX_
#define EPOCH_TIMESTAMP_HXX_

#include <chrono>

template <typename T>
struct is_chrono_duration
{
    static const bool value = false;
};

template <typename Rep, typename Period>
struct is_chrono_duration<std::chrono::duration<Rep, Period>>
{
    static const bool value = true;
};

template <typename Duration = std::chrono::microseconds>
auto EpochTimestamp() -> decltype(std::chrono::duration_cast<Duration>(Duration()).count())
{
    static_assert(is_chrono_duration<Duration>::value, "Duration must be a std::chrono::duration");
    auto duration = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<Duration>(duration).count();
}

#endif