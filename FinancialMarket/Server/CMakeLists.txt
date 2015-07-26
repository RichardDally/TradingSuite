project(FinancialMarketServer CXX)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

# Include Google's Protocol Buffer headers
include_directories(${PROTOBUF_INCLUDE_DIRS})

# Include FinancialMarketLibrary headers
include_directories(${FinancialMarketLibrary_SOURCE_DIR}/headers)

# Include FinancialMarketServer headers
include_directories(headers)

# FinancialMarketServer files
file(GLOB_RECURSE FINANCIAL_MARKET_SERVER_FILES headers/* src/*)

add_executable(FinancialMarketServer ${FINANCIAL_MARKET_SERVER_FILES})

# Adding library headers
include_directories(${FinancialMarketLibrary_BINARY_DIR})
target_link_libraries(FinancialMarketServer FinancialMarketLibrary)