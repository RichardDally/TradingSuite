#pragma once
#ifndef REFERENTIAL_SERIALIZATION_HXX_
#define REFERENTIAL_SERIALIZATION_HXX_

#include <Referential.pb.h>

template <typename AssociativeContainer>
std::tuple<std::string, bool> EncodeReferential(const AssociativeContainer& instruments)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    PB::Referential referential;

    for (const auto& pair : instruments)
    {
        auto pbInstrument = referential.add_instrument();
        pbInstrument->set_id(pair.second->GetInstrumentID());
        pbInstrument->set_isin(pair.second->GetISIN());
        pbInstrument->set_mnemo(pair.second->GetMnemo());
        pbInstrument->set_name(pair.second->GetName());
    }

    std::string serializedReferential;
    const auto success = referential.SerializeToString(&serializedReferential);
    if (success == false)
    {
        // TODO: log error
    }

    return std::make_tuple(serializedReferential, success);
}

template <typename AssociativeContainer, typename DerivedInstrumentType>
std::tuple<AssociativeContainer, bool> DecodeReferential(const std::string& serializedReferential)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    AssociativeContainer instruments;

    PB::Referential referential;
    const auto success = referential.ParseFromString(serializedReferential);
    if (success)
    {
        const auto instrumentSize = referential.instrument_size();
        for (int i = 0; i < instrumentSize; ++i)
        {
            const auto instrumentId = referential.instrument(i).id();
            instruments[instrumentId] = InstrumentFactory::BuildInstrument<DerivedInstrumentType>
                (instrumentId, referential.instrument(i).name(), referential.instrument(i).isin(), referential.instrument(i).mnemo());
        }
    }
    else
    {
        // TODO: log error
    }

    return std::make_tuple(instruments, success);
}

#endif