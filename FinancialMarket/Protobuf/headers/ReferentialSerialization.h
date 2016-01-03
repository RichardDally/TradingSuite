#pragma once
#ifndef REFERENTIAL_SERIALIZATION_H_
#define REFERENTIAL_SERIALIZATION_H_

template <typename AssociativeContainer>
auto EncodeReferential(const AssociativeContainer& instruments);

template <typename AssociativeContainer, typename DerivedInstrumentType>
auto DecodeReferential(const std::string& serializedReferential);

#include "ReferentialSerialization.hxx"

#endif