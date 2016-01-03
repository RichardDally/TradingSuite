#include <gtest/gtest.h>
#include <ReferentialTest.h>
#include <StockInstrument.h>
#include <InstrumentFactory.h>
#include <ReferentialSerialization.h>

TEST(ReferentialSerializationTest, Encode)
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;
    ReferentialExposed<DerivedInstrumentType, SimpleInstrumentTraits> referential;

    const SimpleInstrumentTraits::InstrumentIDType instrumentID = 0;
    const std::string name = "ACCOR";
    const std::string isin = "FR0000120404";
    const std::string mnemo = "AC";

    referential.AddInstrument(InstrumentFactory::BuildInstrument<DerivedInstrumentType>(instrumentID, name, isin, mnemo));
    const auto& container = referential.GetInstrumentsContainer();

    auto encoded = EncodeReferential(container);
    EXPECT_TRUE(std::get<1>(encoded));
}

TEST(ReferentialSerializationTest, Decode)
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;
    ReferentialExposed<DerivedInstrumentType, SimpleInstrumentTraits> referential;

    const SimpleInstrumentTraits::InstrumentIDType instrumentID = 0;
    const std::string name = "ACCOR";
    const std::string isin = "FR0000120404";
    const std::string mnemo = "AC";

    referential.AddInstrument(InstrumentFactory::BuildInstrument<DerivedInstrumentType>(instrumentID, name, isin, mnemo));
    const auto& container = referential.GetInstrumentsContainer();

    auto encoded = EncodeReferential(container);
    EXPECT_TRUE(std::get<1>(encoded));

    using AssociativeContainer = std::decay<decltype(container)>::type;
    auto decoded = DecodeReferential<AssociativeContainer, DerivedInstrumentType>(std::get<0>(encoded));
    EXPECT_EQ(1, std::get<0>(decoded).size());
    EXPECT_TRUE(std::get<1>(decoded));
}