#include <gtest/gtest.h>
#include <StockInstrument.h>
#include <InstrumentFactory.h>
#include <ReferentialSerialization.h>

TEST(ReferentialSerializationTest, Encode)
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;

    const SimpleInstrumentTraits::InstrumentIDType instrumentID = 0;
    const std::string name = "ACCOR";
    const std::string isin = "FR0000120404";
    const std::string mnemo = "AC";

    std::vector<DerivedInstrumentType> instruments;
    instruments.emplace_back(instrumentID, name, isin, mnemo);

    auto encoded = EncodeReferential(instruments);
    EXPECT_TRUE(std::get<1>(encoded));
}

TEST(ReferentialSerializationTest, Decode)
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;

    std::vector<DerivedInstrumentType> beforeEncoding;
    beforeEncoding.emplace_back(0, "ACCOR", "FR0000120404", "AC");

    auto encoded = EncodeReferential(beforeEncoding);
    EXPECT_TRUE(std::get<1>(encoded));

    auto decoded = DecodeReferential<DerivedInstrumentType>(std::get<0>(encoded));
    EXPECT_EQ(beforeEncoding.size(), std::get<0>(decoded).size());
    EXPECT_TRUE(std::get<1>(decoded));
}