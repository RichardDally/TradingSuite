#pragma once
#ifndef REFERENTIAL_SERIALIZATION_H_
#define REFERENTIAL_SERIALIZATION_H_

template <typename DerivedInstrumentType>
std::tuple<std::string, bool> EncodeReferential(const std::vector<DerivedInstrumentType>& instruments);

template <typename DerivedInstrumentType>
std::tuple<std::vector<DerivedInstrumentType>, bool> DecodeReferential(const std::string& serializedReferential);

#include "ReferentialSerialization.hxx"

#endif