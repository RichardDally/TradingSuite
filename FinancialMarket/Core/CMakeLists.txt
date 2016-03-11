project(FinancialMarketCore CXX)

# List all files for Library project
file(GLOB_RECURSE FINANCIAL_MARKET_CORE_FILES headers/* src/*)

include_directories(headers)
add_library(FinancialMarketCore STATIC ${FINANCIAL_MARKET_CORE_FILES})