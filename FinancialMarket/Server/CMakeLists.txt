project(FinancialMarketServer CXX)

# Boost framework
# http://www.boost.org
find_package(Boost 1.40.0 REQUIRED COMPONENTS system date_time regex)

# Google's Protocol Buffer
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

# Include Google's Protocol Buffer headers
include_directories(${PROTOBUF_INCLUDE_DIRS})

# Include FinancialMarketLibrary headers
include_directories(${FinancialMarketCore_SOURCE_DIR}/headers)

# Include FinancialMarketServer headers
include_directories(headers)

# FinancialMarketServer files
file(GLOB_RECURSE FINANCIAL_MARKET_SERVER_FILES headers/* src/*)

add_executable(FinancialMarketServer ${FINANCIAL_MARKET_SERVER_FILES})

# Adding FinancialMarketCore headers
include_directories(${FinancialMarketCore_BINARY_DIR})
target_link_libraries(FinancialMarketServer FinancialMarketCore ${Boost_LIBRARIES})