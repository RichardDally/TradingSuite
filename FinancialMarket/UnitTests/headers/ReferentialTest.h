#pragma once
#ifndef REFERENTIAL_TEST_H_
#define REFERENTIAL_TEST_H_

#include <Referential.h>

/**
* @brief Expose protected attributes/members of ReferentialTest class
*/
template <typename DerivedInstrument, typename InstrumentTraits>
class ReferentialExposed : public Referential<DerivedInstrument, InstrumentTraits>
{
public:
    const typename Referential<DerivedInstrument, InstrumentTraits>::InstrumentContainer& GetInstrumentsContainer() const
    {
        return this->instrumentsMapping_;
    }
};

#endif