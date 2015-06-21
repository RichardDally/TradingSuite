# Setting paths for convenience
set(FINANCIAL_MARKET_LIBRARY_PATH FinancialMarket/Library)
set(FINANCIAL_MARKET_SERVER_PATH FinancialMarket/Server)
set(FINANCIAL_MARKET_UNIT_TESTS_PATH FinancialMarket/UnitTests)

include(FinancialMarket/Library/CMakeLists.txt)
include(FinancialMarket/Server/CMakeLists.txt)
include(FinancialMarket/UnitTests/CMakeLists.txt)