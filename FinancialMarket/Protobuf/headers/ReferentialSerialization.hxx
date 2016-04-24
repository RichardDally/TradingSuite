#pragma once
#ifndef REFERENTIAL_SERIALIZATION_HXX_
#define REFERENTIAL_SERIALIZATION_HXX_

#include <Referential.pb.h>

template <typename DerivedInstrumentType>
std::tuple<std::string, bool> EncodeReferential(const std::vector<DerivedInstrumentType>& instruments)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    PB::Referential referential;

    for (const auto& instrument : instruments)
    {
        auto pbInstrument = referential.add_instrument();
        pbInstrument->set_id(instrument.GetInstrumentID());
        pbInstrument->set_isin(instrument.GetISIN());
        pbInstrument->set_mnemo(instrument.GetMnemo());
        pbInstrument->set_name(instrument.GetName());
    }

    std::string serializedReferential;
    const auto success = referential.SerializeToString(&serializedReferential);
    if (success == false)
    {
        // TODO: log error
    }

    return std::make_tuple(std::move(serializedReferential), success);
}

template <typename DerivedInstrumentType>
std::tuple<std::vector<DerivedInstrumentType>, bool> DecodeReferential(const std::string& serializedReferential)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    std::vector<DerivedInstrumentType> instruments;

    PB::Referential referential;
    const auto success = referential.ParseFromString(serializedReferential);
    if (success)
    {
        const auto instrumentSize = referential.instrument_size();
        for (int i = 0; i < instrumentSize; ++i)
        {
            const auto instrumentId = referential.instrument(i).id();
            instruments.emplace_back(instrumentId, referential.instrument(i).name(), referential.instrument(i).isin(), referential.instrument(i).mnemo());
        }
    }
    else
    {
        // TODO: log error
    }

    return std::make_tuple(std::move(instruments), success);
}

#endif