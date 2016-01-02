project(FinancialMarketCommunication CXX)

# Protobuf headers
include_directories(${PROTOBUF_INCLUDE_DIRS})

# Generate Protobuf header and source files
protobuf_generate_cpp(PROTO_SRC PROTO_HEADERS ProtobufMessages/*.proto)

# Other projects depends on these generated files
#set(PROTO_SRC ${PROTO_SRC} PARENT_SCOPE)
set(PROTO_HEADERS ${PROTO_HEADERS} PARENT_SCOPE)

# List all files for Library project
file(GLOB_RECURSE FINANCIAL_MARKET_LIBRARY_FILES headers/* src/*)

include_directories(headers)
add_library(FinancialMarketCommunication STATIC ${FINANCIAL_MARKET_LIBRARY_FILES} ${PROTO_SRC} ${PROTO_HEADERS})