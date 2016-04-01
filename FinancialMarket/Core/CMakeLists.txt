project(FinancialMarketCore CXX)

# Boost framework
# http://www.boost.org
find_package(Boost REQUIRED)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

# List all files for Library project
file(GLOB_RECURSE FINANCIAL_MARKET_CORE_FILES headers/* src/*)

include_directories(headers)
add_library(FinancialMarketCore STATIC ${FINANCIAL_MARKET_CORE_FILES})