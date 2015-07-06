#include <gtest/gtest.h>

#include <string>
#include <ReferentialTest.h>
#include <StockInstrument.h>
#include <InstrumentFactory.h>

TEST(ReferentialTest, AddInstrument)
{
    using SimpleInstrumentTraits = InstrumentTraits<int>;
    using DerivedInstrumentType = StockInstrument<SimpleInstrumentTraits>;
    ReferentialExposed<DerivedInstrumentType, SimpleInstrumentTraits> referential;

    const SimpleInstrumentTraits::InstrumentIDType instrumentID = 0;
    const std::string name = "ACCOR";
    const std::string isin = "FR0000120404";
    const std::string mnemo = "AC";

    referential.AddInstrument(InstrumentFactory::BuildInstrument<DerivedInstrumentType>(instrumentID, name, isin, mnemo));
    EXPECT_EQ(1, referential.GetInstrumentsContainer().size());

    auto weak = referential.GetInstrument(instrumentID);
    auto strong = weak.lock();

    EXPECT_TRUE(strong.operator bool());
    if (strong)
    {
        EXPECT_EQ(name, strong->GetName());
        EXPECT_EQ(isin, strong->GetISIN());
        EXPECT_EQ(mnemo, strong->GetMnemo());
    }
}
