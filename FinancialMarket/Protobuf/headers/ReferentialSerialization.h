#pragma once
#ifndef REFERENTIAL_SERIALIZATION_H_
#define REFERENTIAL_SERIALIZATION_H_

template <typename AssociativeContainer>
std::tuple<std::string, bool> EncodeReferential(const AssociativeContainer& instruments);

template <typename AssociativeContainer, typename DerivedInstrumentType>
std::tuple<AssociativeContainer, bool> DecodeReferential(const std::string& serializedReferential);

#include "ReferentialSerialization.hxx"

#endif