cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(TradingSimulator CXX)

# Google's Protocol Buffer is mandatory
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Generate Protobuf header and source files
protobuf_generate_cpp(PROTO_SRC PROTO_HEADERS thirdparty/protobuf/InstrumentMessage.proto)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(headers)
file(GLOB_RECURSE TRADING_SIMULATOR_FILES src/* headers/*)

add_executable(TradingSimulator ${TRADING_SIMULATOR_FILES} ${PROTO_SRC} ${PROTO_HEADERS})
target_link_libraries(TradingSimulator ${PROTOBUF_LIBRARIES})