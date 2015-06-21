# Google's Protocol Buffer is mandatory
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Generate Protobuf header and source files
protobuf_generate_cpp(PROTO_SRC PROTO_HEADERS thirdparty/protobuf/InstrumentMessage.proto)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(FINANCIAL_MARKET_LIBRARY_BINARY FinancialMarketLibrary)
include_directories(${FINANCIAL_MARKET_LIBRARY_PATH}/headers)
file(GLOB_RECURSE FINANCIAL_MARKET_LIBRARY_FILES ${FINANCIAL_MARKET_LIBRARY_PATH}/headers/* ${FINANCIAL_MARKET_LIBRARY_PATH}/src/*)

add_library(${FINANCIAL_MARKET_LIBRARY_BINARY} STATIC ${FINANCIAL_MARKET_LIBRARY_FILES} ${PROTO_SRC} ${PROTO_HEADERS})