#pragma once
#ifndef INSTRUMENT_FACTORY_H_
#define INSTRUMENT_FACTORY_H_

#include <memory>

struct InstrumentFactory
{
    template <typename DerivedInstrument, typename... Args>
    static std::shared_ptr<DerivedInstrument> BuildInstrument(Args&&... args)
    {
        return std::make_shared<DerivedInstrument>(std::forward<Args>(args)...);
    }

    template <typename DerivedInstrument, typename... Args>
    static std::unique_ptr<DerivedInstrument> BuildLightInstrument(Args&&... args)
    {
        return std::unique_ptr<DerivedInstrument>(new DerivedInstrument(std::forward<Args>(args)...));
    }
};

#endif
